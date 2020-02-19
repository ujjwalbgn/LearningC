//Written by Ujjwal Bajagain 1001643752

#ifndef DRAWTOOL
#define DRAWTOOL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxSize 20

void initilizeMap(char array[maxSize][maxSize], int *userInputSize);

void printMap(char array[maxSize][maxSize], int userInputSize);

void drawLines(char array[maxSize][maxSize], char initialCommand, int rowno, int colno, int noSpot, char mark);

void drawLetters(char drawCommands[], char array[maxSize][maxSize], int printNumber);

#endif
