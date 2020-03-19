#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "wordCount.h"
#include "hashTable.h"
#include "getWord.h"

int main (int argc, char *argv[]) {
    int fd, fileCount = 0;
    FILE *file = NULL;
    char *word, *word1, *pair;
    int count = 0;
    hashTable *table = newTable(30);

    // if no arguments are entered when the user runs the program exit
    if (argc == 1) {
        fprintf(stdout, "ERROR: No valid file paths found, exiting...\n");
        deleteTable(table);
        exit(1);
    }

    for (int ii = 1; ii < argc; ii++) { // iterate through the arguments entered by the user

        // check if the file path is not valid or an argument for count was entered
        while ((fd = open(argv[ii], O_RDONLY) < 0) || argv[ii][0] == '-') {
            if (argv[ii][0] == '-') {       // set count to equal argv[ii]
                count = atoi(argv[ii]) * -1;
                if (ii < argc) ii++;        // increment ii to the next argument in argv
                if (ii == argc) break;
            }
            else {
                fprintf(stdout, "ERROR: %s does not exist\n", argv[ii]);    //print the invalid file path entered
                if (ii < argc) ii++;        // increment ii to the next argument in argv
                else break;
            }
        }

        if ((ii == argc) && (fileCount == 0)) { //if all arguments have been checked an no valid file entered exit
            fprintf(stdout, "ERROR: No valid file paths found, exiting...\n");
            deleteTable(table);
            exit(1);
        }

        if (ii < argc) {
            if ((file = fopen(argv[ii], "r")) != NULL) {
                word = getNextWord(file);
                while ((word1 = getNextWord(file)) != NULL) {

                    pair = wordPair(word, word1);
                    free(word);
                    word = strdup(word1);
                    free(word1);
                    table = insert(table, pair, 1);
                    free(pair);
                }
                free(word);
                free(word1);
                fileCount++;
            }
            if (file != NULL) fclose(file);
        }
    }
    /*
     * if no argument for count is entered by the user or the argument is higher than the number of word pairs
     * set count to the maximum number of valid word pairs
    */
    if (count == 0 || count > (table->currentTableSize + table->collisions)) {
        count = table->currentTableSize + table->collisions;
    }

    printWords(wordFrequency(table), count);
    cleanup(table);
    deleteTable(table);

    return 0;
}
