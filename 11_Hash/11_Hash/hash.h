#ifndef HASH_H
#define HASH_H
#define KEY_SIZE 10
#define TABLE_SIZE 13
#include <stdlib.h>
#include <stdio.h>
typedef struct
{
	char key[KEY_SIZE];
}HashElement;

HashElement HashTable[TABLE_SIZE];

void HashTable_init(HashElement ht[]);
int trans(char *key);
int hash_function(char *key);

#define empty(e) (strlen(e.key) == 0)
#define equal(e1, e2) (!strcmp(e1.key, e2.key))

void hash_lp_add(HashElement item, HashElement ht[]);
void hash_lp_search(HashElement item, HashElement ht[]);

void hash_lp_print(HashElement ht[]);


typedef struct listNode
{
	HashElement item;
	struct listNode* link;
}ListNode;
ListNode *lHashTable[TABLE_SIZE];
#endif