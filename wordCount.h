#ifndef CS360A1_WORDCOUNT_H
#define CS360A1_WORDCOUNT_H

#include "hashTable.h"

/*
 * interface for wordCount.c
 * used to combine two words into a single string,
 * sort the word pairs into descending order using
 * qsort which uses the comparator method and
 * printWords to print the word pairs in descending order
 * to stdout
 */

char *wordPair(char *s1, char*s2);
node *wordFrequency(hashTable *h);
int comparator(const void *a, const void *b);
void printWords(node *array, int count);

#endif //CS360A1_WORDCOUNT_H
