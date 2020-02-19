//Written by Ujjwal Bajagain 1001643752

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "DiceLib.h"

int fullHouseChecker = 0;
int largeStraight = 0;
int smallStraight = 0;
int straight = 0;

int RollDice(int diceArray[])
{
    srand(time(NULL));
    int i = 0;
    for (i; i < dice; i++)
    {
        int x = rand() % 6 + 1;
        diceArray[i] = x;
    }
}

void PrintRoll(int diceArray[])
{
    int j;
    for (j = 0; j < dice; j++)
    {
        printf(" %d  ", diceArray[j]);
    }
    printf("\n");
}

//How Many
void HowManyFaces(int diceArray[], int HowMany[])
{
    int i = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0;
    for (i = 0; i < dice; i++)
    {
        if (diceArray[i] == 1)
        {
            HowMany[0] = ++m;
        }
        else if (diceArray[i] == 2)
        {
            HowMany[1] = ++n;
        }
        else if (diceArray[i] == 3)
        {
            HowMany[2] = ++o;
        }
        else if (diceArray[i] == 4)
        {
            HowMany[3] = ++p;
        }
        else if (diceArray[i] == 5)
        {
            HowMany[4] = ++q;
        }
        else if (diceArray[i] == 6)
        {
            HowMany[5] = ++r;
        }
    }
}

void GameLogic(int HowMany[], char result[])
{
    int nothing = 1;
    int i;
    for (i = 0; i < face; i++)
    {
        if (HowMany[i] == 5)
        {
            strcpy(result, "CSlang !\n");
            nothing = 0;
            break;
        }
        else if (HowMany[i] == 4)
        {
            strcpy(result, "4 of a kind\n");
            nothing = 0;
            break;
        }

        else if (HowMany[i] == 3)
        {
            int j;
            for (j = 0; j < face; j++)
            {
                if (HowMany[j] == 2)
                {
                    strcpy(result, "Full House\n");
                    fullHouseChecker = 1;
                    nothing = 0;
                    break;
                }
            }
            if (fullHouseChecker == 0)
            {
                strcpy(result, "3 of a kind \n");
                nothing = 0;
                break;
            }
            fullHouseChecker = 0;
        }
        else if (HowMany[i] == 2)
        {
            int j;
            for (j = i + 1; j < face; j++)
            {
                if (HowMany[j] == 2)
                {
                    strcpy(result, "2 pairs\n");
                    nothing = 0;
                    break;
                }
            }
            if (nothing == 0)
            {
                break;
            }
        }

        else if (HowMany[i] == 1)
        {
            largeStraight += 1;
        }
        else if ((HowMany[i] == 0) && largeStraight < 5)
        {
            largeStraight = 0;
        }

        if (HowMany[i] >= 1)
        {
            smallStraight++;
        }
        else if (HowMany[i] == 0 && smallStraight > 0 && smallStraight < 4)
        {
            smallStraight = 0;
        }
    }

    if (largeStraight == 5)
    {
        strcpy(result, "You have Large Straight.\n");
        largeStraight = 0;
        nothing = 0;
    }
    else if (smallStraight >= 4)
    {
        strcpy(result, "You have Small Straight.\n");
        nothing = 0;
        smallStraight = 0;
    }

    if (nothing == 1)
    {
        strcpy(result, "you have nothing\n");
        smallStraight = 0;
        largeStraight = 0;
    }
}
