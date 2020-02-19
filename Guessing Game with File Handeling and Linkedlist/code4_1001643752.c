//Written by Ujjwal Bajagain 1001643752

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "GameLib.c"

#include "GameLib.h"

int main(int argc, char *argv[])
{
    AWARD AwardArray[MAX_ENTRIES];
    int UserSelectedMenu = 1;

    FILE *fh = OpenAwardFile(argc, argv);

    int nolines = FillAwardArray(AwardArray, fh);

    printf("\nWelcome to the Academy Awards Guessing Game\n");

    while (UserSelectedMenu)
    {
        int UserSelectedMenu = PrintAwardMenu(AwardArray, nolines);
        if (UserSelectedMenu != 0)
        {
            GuessIt(&AwardArray[UserSelectedMenu - 1]);
        }
        
    }

    //free memory
    int i;
    for (i = 0; i < nolines; i++)
    {
        free(AwardArray[i].category);
        free(AwardArray[i].winner);
    }

    return 0;
}
