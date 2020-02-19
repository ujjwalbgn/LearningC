//Written by Ujjwal Bajagain 1001643752

#include "GameLib.h"

FILE *OpenAwardFile(int argc, char *argv[])
{
    char filename[65] = "";
    FILE *fh;

    if (argc == 2)
    {
        strcpy(filename, argv[1]);
    }
    else
    {
        printf("\nMust be run with an input file name.");
        printf("\nPlease enter the filename: ");
        fgets(filename, 64, stdin);
        filename[strlen(filename) - 1] = '\0';
    }

    do
    {
        fh = fopen(filename, "r");
        if (fh == NULL)
        {
            printf("\nCould not open input file named %s.\n", filename);
            printf("\nPlease enter the filename: ");
            fgets(filename, 64, stdin);
            filename[strlen(filename) - 1] = '\0';
        }

    } while (fh == NULL);

    return fh;
}

int FillAwardArray(AWARD AwardArray[MAX_ENTRIES], FILE *fh)
{
    char buffer[65];
    int noLines = 0;
    char *token;

    while (fgets(buffer, sizeof(buffer) - 1, fh) && noLines < MAX_ENTRIES)
    {
        token = strtok(buffer, "|");
        strcpy(AwardArray[noLines].year, token);
        //printf("\nyear: %s \n", AwardArray[noLines].year);
        token = strtok(NULL, "|");
        AwardArray[noLines].category = malloc(strlen(token) * sizeof(char *));
        strcpy(AwardArray[noLines].category, token);
        //printf("\ncategory: %s\n ", AwardArray[noLines].category);
        token = strtok(NULL, "|");
        AwardArray[noLines].winner = malloc(strlen(token) * sizeof(char *));
        strcpy(AwardArray[noLines].winner, token);

        noLines++;
    }

    fclose(fh);
    return noLines;
}

int PrintAwardMenu(AWARD AwardArray[], int nolines)
{
    printf("\n0. Exit\n");
    int UserSelectedMenu = 0;
    int i;
    do
    {
        for (i = 0; i < nolines; i++)
        {
            printf("%d. %s %s \n", i + 1, AwardArray[i].year, AwardArray[i].category);
        }

        printf("\n\nPick a category: ");
        scanf("%d", &UserSelectedMenu);
        if (UserSelectedMenu == 0)
        {
            exit(0);
        }
    } while (UserSelectedMenu < 0 || UserSelectedMenu > nolines);
    return UserSelectedMenu;
}

void GuessIt(AWARD *AwardArray)
{
    // srand(time(NULL));
    int WinnerLen = strlen(AwardArray->winner);
    int noGuess = (rand() % (WinnerLen/2)) +3;

    printf("\nYou have %d guesses to guess the winner of the \n",noGuess);
    printf ("%s in %s\n", AwardArray->category,AwardArray->year);

    char orginalWin[WinnerLen];
    strcpy(orginalWin,AwardArray->winner);

    char upperWin[WinnerLen];
    // strcpy(upperWin, strupr(AwardArray->winner));
    int j;
    for(j =0; j < WinnerLen;j++)
    {
        upperWin[j] = toupper(orginalWin[j]);
    }
    upperWin[WinnerLen] = '\0';

    // printf("UpperWin:%s",upperWin);

    char dashedWin[WinnerLen];
    strcpy(dashedWin,upperWin);
    char dashSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char *dashingStr;
    dashingStr = strpbrk (dashedWin,dashSet);
    while (dashingStr != NULL)
    {
        *dashingStr = '-';
        dashingStr = strpbrk (dashedWin,dashSet);
    }
    printf("%s \n",dashedWin);
    //printf("%d \n",WinnerLen);
    int i;
    do
    {
        char userInput; 
        char *guessPointer;
        char  *startPosition = &upperWin[0];
        int PointerDistance;

        printf("Player: Guess a letter : ");
        scanf(" %c", &userInput);
        userInput = toupper(userInput);
        guessPointer = strchr(upperWin,userInput);
        if(guessPointer == NULL)
        {
            noGuess--;
            if (noGuess != 0)
            {
            printf("\nYou have %d guesses left\n", noGuess);
            }
            printf("\n%s\n",dashedWin);

        } else
        {
            while (guessPointer != NULL)
            {
            PointerDistance = abs(guessPointer-startPosition);
            dashedWin[PointerDistance] = orginalWin[PointerDistance];
            upperWin[PointerDistance] = '-';
            guessPointer = strchr(upperWin,userInput);
            }
            printf("\n%s\n",dashedWin);

        }        

    } while (noGuess != 0 && strstr(AwardArray->winner,dashedWin) == NULL);
    
    if(strstr(orginalWin,dashedWin) != NULL)
    {
        orginalWin[WinnerLen-1] = '\0';
        printf("You guessed correctly!!\n");
		printf("The winner of the %s %s was \"%s.\"\n\n", AwardArray->year, AwardArray->category, orginalWin);
    } 
    else if (noGuess == 0)
    {
        printf("You are out of guesses.\n");
    }
}
