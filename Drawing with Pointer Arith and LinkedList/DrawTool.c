//Written by Ujjwal Bajagain 1001643752

#include "DrawTool.h"

void initilizeMap(char array[maxSize][maxSize], int *userInputSize)
{
    char bgcharacter;
    int i, j;

    printf("Enter the background character :");
    scanf(" %c", &bgcharacter);
    //getchar();

    for (i = 0; i < *userInputSize; i++)
    {
        for (j = 0; j < *userInputSize; j++)
        {
            *(*(array + i) + j) = bgcharacter;
        }
    }
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

void drawLetters(char drawCommands[], char array[maxSize][maxSize], int userInpuStrLen)
{
    char initialCommand;
    int userInputSize = maxSize;
    char *token;
    char mark;
    char delim[4] = "(,)";
    int rowno, colno, noSpot;

    // printf("searchCount %d", searchCount);

    token = strtok(drawCommands, delim);
    // printf("%s", token);

    if (token != NULL)
    {
        initialCommand = toupper(token[0]);
        if (initialCommand == 'P' || initialCommand == 'V' || initialCommand == 'H')
        {
            token = strtok(NULL, delim);
            rowno = atoi(token);
            if (rowno >= userInputSize)
            {
                printf("Invalid row number\n");
                return;
            }

            token = strtok(NULL, delim);
            colno = atoi(token);

            if (userInpuStrLen == 1)
            {
                // printf("userInpuStrLen %d", userInpuStrLen);
                colno = colno + 7;
            }
            else if (userInpuStrLen == 2)
            {
                colno = colno + 14;
            }

            if (colno >= userInputSize)
            {
                printf("Invalid column no\n");
                return;
            }

            token = strtok(NULL, delim);
            noSpot = atoi(token);

            token = strtok(NULL, delim);
            if (token == NULL)
            {
                mark = 'X';
                // printf("%c", mark);
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
                if ((+rowno) > (userInputSize))
                {
                    printf("Spot out of bound for column \n");
                    return;
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
                    return;
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
                    return;
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
            return;
        }
    }
}
