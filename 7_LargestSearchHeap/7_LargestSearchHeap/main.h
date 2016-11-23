#ifndef LARGETST_SEARCH_MAIN_H
#define LARGETST_SEARCH_MAIN_H

void getDS(char DStoUse[]);
void loopEntry(char DStoUse[]);
int isAvailableDS(char DStoUse[]);
int isCommand(char input[]);
int isInputEnd();
void excuteCommand(char input[], char DStoUse[]);

void parse(char input[], int size);

void selectInsert(char DStoUse[]);

int insertBST();
int insertMaxHeap();

int listBST();
int listMaxHeap();

int largestSearchBST();
int largestSearchMaxHeap();

#endif
