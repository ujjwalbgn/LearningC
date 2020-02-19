//Written by Ujjwal Bajagain 1001643752

#ifndef GAMELIB
#define GAMELIB

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include <time.h>

#define MAX_ENTRIES 15

typedef struct 
{
    char year[5];
    char *category;
    char *winner;
} AWARD;

FILE *OpenAwardFile(int argc, char *argv[]);

int FillAwardArray(AWARD AwardArray[MAX_ENTRIES], FILE *fh);

int PrintAwardMenu(AWARD AwardArray[], int nolines);

void GuessIt(AWARD *AwardArray);

#endif 
