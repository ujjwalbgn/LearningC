//Written by Ujjwal Bajagain 1001643752
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawTool.c"
#include "DrawTool.h"

int main()
{
    int userInputSize = 0;
    char array[maxSize][maxSize];
    char drawCommands[100];
    char *commandToken;
    char *token;
    char initialCommand;
    char mark;
    char delim[4] = "(,)";
    int startPoints[3] = {0, 0, 0};
    int rowno, colno, noSpot;

    initilizeMap(array, &userInputSize);

    PrintInstructions();

    printMap(array, userInputSize);

    do
    {
        printf("Enter draw command (enter Q to quit) : ");
        fgets(drawCommands, 99, stdin);
     //  drawCommands[strlen(drawCommands) - 1] = '\0';

        token = strtok(drawCommands, delim);
        //printf("%s", token);

        if (token != NULL)
        {
            initialCommand = toupper(token[0]);
            if (initialCommand == 'Q' || initialCommand == 'q')
            {
                //printf("\nQ\n");
                break;
            }
            if (initialCommand == 'P' || initialCommand == 'V' || initialCommand == 'H')
            {
                token = strtok(NULL, delim);
                rowno = atoi(token);
                if (rowno >= userInputSize)
                {
                    printf("Invalid row number\n");
                    continue;
                }

                token = strtok(NULL, delim);
                colno = atoi(token);
                if (colno >= userInputSize)
                {
                    printf("Invalid column no\n");
                    continue;
                }

                token = strtok(NULL, delim);
                noSpot = atoi(token);

                token = strtok(NULL, delim);
                if (token == NULL)
                {
                    mark = 'X';
                    //printf("%c", mark);
                }
                else
                {
                    mark = *token;
                }

                if (initialCommand == 'P')
                {
                    *(*(array + rowno) + colno) = mark;
                }
                else if (initialCommand == 'V')
                {
                    if ((  + rowno) > (userInputSize))
                    {
                        printf("Spot out of bound for column \n");
                        continue;
                    }
                    else
                    {
                        drawLines(array, initialCommand, rowno, colno, noSpot, mark);
                    }
                }
                else if (initialCommand == 'H')
                {
                    if ((noSpot + colno) > (userInputSize))
                    {
                        printf("Spot is out of bound. Please try again\n");
                        continue;
                    }
                    else
                    {
                        drawLines(array, initialCommand, rowno, colno, noSpot, mark);
                    }
                }
                else if (initialCommand == 'V')
                {
                    if ((noSpot + colno) > (userInputSize))
                    {
                        printf("Spot is out of bound. Please try again\n");
                        continue;
                    }
                    else
                    {
                        drawLines(array, initialCommand, rowno, colno, noSpot, mark);
                    }
                }
            }
            else
            {
                printf("That draw command is unknown\n");
                continue;
            }
            printMap(array, userInputSize);
        }
    }
    while (initialCommand != 'Q' || initialCommand != 'q');
    return 0;
}
