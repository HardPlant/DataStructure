#ifndef LARGETST_SEARCH_MAIN_H
#define LARGETST_SEARCH_MAIN_H

void getDS(char DStoUse[]);
void loopEntry(char DStoUse[]);
void* allocateDS(char DStoUse[]);
int isAvailableDS(char DStoUse[]);
int isCommand(char input[]);
int isInputEnd();
void excuteCommand(char input[], char DStoUse[], void* createdDS);
int insertCommand(createdDS, insertFunc);
void parse(char input[], int size);

void selectInsert(char DStoUse[], void* createdDS);

void insertBST(void* createdDS, int data);
void insertMaxHeap(void* createdDS, int data);

int listBST();
int listMaxHeap();

int largestSearchBST();
int largestSearchMaxHeap();

#endif
