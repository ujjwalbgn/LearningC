//Written by Ujjwal Bajagain 1001643752

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DiceLib.h"

int main()
{
    int diceArray[dice];
    int HowMany[face] = {0, 0, 0, 0, 0, 0};
    int numberOfReRolls = 2;
    int numberOfRolls = 0;
    char result[100];

    printf("\nWritten by Ujjwal Bajagain 1001643752 \n\n");

    for (numberOfRolls = 0; numberOfRolls < numberOfReRolls; numberOfRolls++)
    {
        //TestRollDice(diceArray);
        RollDice(diceArray);
        PrintRoll(diceArray);

        int i;
        for (i = 0; i < face; i++)
        {
            HowManyFaces(diceArray, HowMany);
        }
        
        GameLogic(HowMany, result);
        printf(result);
        
        int j;
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
