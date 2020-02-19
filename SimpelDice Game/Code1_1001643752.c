//Written by Ujjwal Bajagain 1001643752

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DiceTest.c"

//Defines
#define dice 5
#define face 6

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

int main()
{
    int diceArray[dice];
    int HowMany[face] = {0, 0, 0, 0, 0, 0};
    int numberOfReRolls = 200;
    int numberOfRolls = 0;
    int fullHouseChecker = 0;
    int largeStraight = 0;
    int smallStraight = 0;
    int straight = 0;

    printf("\nWritten by Ujjwal Bajagain 1001643752 \n\n");

    for (numberOfRolls = 0; numberOfRolls < numberOfReRolls; numberOfRolls++)
    {
        TestRollDice(diceArray);
        int i;
        int nothing = 1;

        int m = 0, n = 0, o = 0, p = 0, q = 0, r = 0;

        //How Many
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

        for (i = 0; i < face; i++)
        {
            if (HowMany[i] == 5)
            {
                printf("CSlang ! \n");
                nothing = 0;
                break;
            }
            else if (HowMany[i] == 4)
            {
                printf("4 of a kind\n");
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
                        printf("Full House \n");
                        fullHouseChecker = 1;
                        nothing = 0;
                        break;
                    }
                }
                if (fullHouseChecker == 0)
                {
                    printf("3 of a kind \n");
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
                        printf("2 pairs \n");
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
            printf("You have Large Straight.\n");
            largeStraight = 0;
            nothing = 0;
        }
        else if (smallStraight >= 4)
        {
            printf("You have Small Straight.\n");
            nothing = 0;
            smallStraight = 0;
        }

        if (nothing == 1)
        {
            printf("you have nothing\n");
            smallStraight = 0;
            largeStraight = 0;
        }

        //Displays the faces(numbers) of rolled dice
        int j;
        for (j = 0; j < dice; j++)
        {
            printf(" %d  ", diceArray[j]);
        }
        printf("\n");

        for (j = 0; j < 6; j++)
        {
            //Used for testing, to print the result of how many dice of which face's we have
            //printf("How many %d = %d, ", j + 1, HowMany[j]);

            //clear the HowMany count;
            HowMany[j] = 0;
        }
        printf("\n");

        //Collect user input to check if the user onces the roll it again.
        if (numberOfRolls < numberOfReRolls - 1)
        {
            char exit;
            printf("Press any key to roll the dice or N to exit: ");
            scanf(" %c", &exit);
            if (exit == 'n' || exit == 'N')
            {
                break;
            }
            printf("\n");
        }
    }
    return 0;
}
