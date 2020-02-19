//Written by Ujjwal Bajagain 1001643752
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
#include "DrawTool.h"

void initilizeMap(char array[maxSize][maxSize], int *userInputSize)
{
       char bgcharacter;
       int i, j;
       do
       {
              printf("How big is the array? (Enter the value between 1 and 20) ");
              scanf(" %d", userInputSize);
              getchar();
       } while (*userInputSize < 1 || *userInputSize > maxSize);

       printf("Enter the background character? ");
       scanf(" %c", &bgcharacter);
       getchar();

       for (i = 0; i < *userInputSize; i++)
       {
              for (j = 0; j < *userInputSize; j++)
              {
                     *(*(array + i) + j) = bgcharacter;
              }
       }
}

void PrintInstructions()
{
       printf("/n");
       printf("Draw commands start with \n");
       printf("\n");
       printf("\tP for a single point\n"
              "\tH for a horizontal line\n"
              "\tV for a vertical line \n"
              "\n");
       printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark\n"
              "enclosed in () and separated by commas and then the character for the mark.\n"
              "'X' will be used if a mark is not entered. For example,\n");
       printf("\n\t P(2,3,1)* \t start at point 2,3 in the array and mark one spot\n"
              "\t\t\t with an *. For P, the 3rd parameter is ignored.\n");
       printf("\n\t V(1,2,3)$ \t start at point 1,2 in the array and mark the next\n"
              "\t\t\t 3 spots down from the current position with $\n");
       printf("\n\t H(4,6,7)# \t start at point 4,6 in the array and mark the next\n"
              "\t\t\t 7 spots to the right with # \n\n");
       printf("Coordinates out of range and lines drawn past the borders are not allowed.\n"
              "\nEnter Q at the draw command prompt to quit\n"
              "\nPress <ENTER> to continue\n");
       // getchar();
}

void printMap(char array[maxSize][maxSize], int userInputSize)
{
       //to get the enter to continue
       int i, j;
       printf("\n\n");
       for (i = 0; i < userInputSize; i++)
       {
              for (j = 0; j < userInputSize; j++)
              {
                     printf("%c  ", *(*(array + i) + j));
              }
              printf("\n");
       }
       printf("\n");
}

void drawLines(char array[maxSize][maxSize], char initialCommand, int rowno, int colno, int noSpot, char mark)
{
       int i;
       if (initialCommand == 'V')
       {
              for (i = 0; i < noSpot; i++)
              {
                     *(*(array + rowno + i) + colno) = mark;
              }
       }
       else
       {
              for (i = 0; i < noSpot; i++)
              {
                     *(*(array + rowno) + colno + i) = mark;
              }
       }
}
