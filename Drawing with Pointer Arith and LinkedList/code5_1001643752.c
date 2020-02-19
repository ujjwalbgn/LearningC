//Written by Ujjwal Bajagain 1001643752
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// #include "DrawTool.c"
// #include "ListLib.c"

#include "ListLib.h"
#include "DrawTool.h"

//Functions
FILE *OpenFile(int argc, char *argv[])
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

int main(int argc, char *argv[])
{
    int userInputSize = maxSize;
    char array[maxSize][maxSize];
    char drawCommands[100];
    char *commandToken;

    char buffer[65];

    int startPoints[3] = {0, 0, 0};
    int rowno, colno, noSpot;

    nodeData *LinkedListHead = NULL;
    char userInput[100];
    char alphabet[3];

    FILE *fh = OpenFile(argc, argv);

    initilizeMap(array, &userInputSize);

    //read file
    while (fgets(buffer, sizeof(buffer) - 1, fh))
    {
        char *letter;
        char *drawCommands;

        letter = strtok(buffer, "|");
        // printf("%s\n",letter);

        drawCommands = strtok(NULL, "|");
        // printf("%s\n",drawCommands);

        AddNode(letter, drawCommands, &LinkedListHead);
    }

    fclose(fh);

    // print_list(LinkedListHead);
    printf("Please Enter 1-3 letters : ");
    scanf(" %s", userInput);

    int userInpuStrLen = strlen(userInput);
    while (userInpuStrLen < 1 || userInpuStrLen > 3)
    {
        printf("Invalid\n");
        printf("Please Enter 1-3 letters : ");
        scanf(" %s", userInput);
        userInpuStrLen = strlen(userInput);
    }
    int i;
    for (i = 0; i < userInpuStrLen; i++)
    {
        alphabet[i] = toupper(userInput[i]);
        // printf("%c\n",alphabet[i]);
        search(LinkedListHead, alphabet[i], array, i);
    }
    printMap(array, userInputSize);

    return 0;
}
