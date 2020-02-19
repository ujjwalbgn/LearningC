//Written by Ujjwal Bajagain 1001643752

#ifndef LISTLIB
#define LISTLIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "DrawTool.h"

typedef struct node
{
    char letter;
    char *drawCommands;
    struct node *next_ptr;
} nodeData;

nodeData* AddNode(char *letter, char *drawCommands, nodeData **LinkedListHead);

// void print_list(nodeData * LinkedListHead);

void search(nodeData * LinkedListHead, char x,char array[maxSize][maxSize],int printNumber);

#endif
