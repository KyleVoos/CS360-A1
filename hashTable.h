#ifndef CS360A1_HASHTABLE_H
#define CS360A1_HASHTABLE_H

typedef struct _node {
    char *key;
    int count;
    struct _node *next;
} node;

typedef struct _hashTable {
    int currentTableSize;
    int maxTableSize;
    int collisions;
    node **table;
} hashTable;

hashTable *newTable(int tableSize);
node *newNode(char *key, int count);
unsigned long long getIndex(unsigned long long hash, hashTable *h);
hashTable *insert(hashTable *h, char *key, int frequency);
hashTable *rehash(hashTable *h);
hashTable *rehashInsert(hashTable *h, node *n);
void deleteNode(node *n);
void deleteTable(hashTable *h);
void cleanup(hashTable *h);

#endif //CS360A1_HASHTABLE_H
