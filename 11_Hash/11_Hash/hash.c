#include "hash.h"


void HashTable_init(HashElement ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		ht[i].key[0] = NULL;
}

int trans(char *key)
{
	int number = 0;
	while (*key)
		number += *key++;
	return number;
}
int hash_function(char *key)
{
	return trans(key) % TABLE_SIZE;
}

void hash_lp_add(HashElement item, HashElement ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i]))
		{
			fprintf(stderr,"Ž�� Ű �ߺ�"); return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value)
		{
			fprintf(stderr, "���̺� Ǯ"); return;
		}
	}
	ht[i] = item;
}
void hash_lp_search(HashElement item, HashElement ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i]))
		{
			fprintf(stderr, "Ž������, ��ġ = %d\n",i); return;
		}

		i = (i + 1) % TABLE_SIZE;

		if (i == hash_value)
		{
			fprintf(stderr, "Ž�� ����"); return;
		}
	}

	fprintf(stderr, "Ž�� ����"); return;
}

void hash_lp_print(HashElement ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
}

void hash_qp_add(HashElement item, HashElement ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i]))
		{
			fprintf(stderr, "Ž�� Ű �ߺ�"); return;
		}
		i = (hash_value+inc*inc) % TABLE_SIZE;
		inc = inc + 1;
		if (i == hash_value)
		{
			fprintf(stderr, "���̺� Ǯ"); return;
		}
	}
	ht[i] = item;
}
int hash_function2(char *key)
{
	return trans(key) % (TABLE_SIZE - 2);
}
void hash_dh_add(HashElement item, HashElement ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i]))
		{
			fprintf(stderr, "Ž�� Ű �ߺ�"); return;
		}
		i = (i+inc) % TABLE_SIZE;
		inc = inc + 1;
		if (i == hash_value)
		{
			fprintf(stderr, "���̺� Ǯ"); return;
		}
	}
	ht[i] = item;
}

void hash_chain_add(HashElement item, ListNode *ht[])
{
	int hash_value = hash_function(item.key);
	ListNode *ptr;
	ListNode *node_before = NULL;
	ListNode *node = ht[hash_value];
	for (; node; node_before = node, node = node->link)
	{
		if (equal(node->item,item))
		{
			fprintf(stderr, "�̹� �����\n"); return;
		}
	}
	ptr=(ListNode*)malloc(sizeof(ListNode));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}
void hash_chain_find(HashElement item, ListNode *ht[])
{
	ListNode *node;
	int hash_value = hash_function(item.key);
	for (node=ht[hash_value]; node; node = node->link)
	{
		if (equal(node->item, item))
		{
			fprintf(stderr, "Ű �߰�\n"); return;
		}
	}
	fprintf(stderr, "Ű ã�� �Ұ�\n"); return;
}