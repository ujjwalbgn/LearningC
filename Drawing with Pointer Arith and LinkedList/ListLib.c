//Written by Ujjwal Bajagain 1001643752

#include "ListLib.h"

nodeData* AddNode(char* letter, char* drawCommands, nodeData **LinkedListHead)
{
    nodeData *TempPtr, *NewNode;
    NewNode = malloc(sizeof(nodeData));
    NewNode->letter = *letter;
    NewNode->drawCommands = (char*) (malloc(strlen(drawCommands) * sizeof(char)));
    strcpy (NewNode->drawCommands, drawCommands);
    NewNode->next_ptr = NULL;
    if (*LinkedListHead == NULL)
    {
        *LinkedListHead = NewNode;
    }
    else
    {
        TempPtr = *LinkedListHead;
        while (TempPtr->next_ptr != NULL)
        {
            TempPtr = TempPtr->next_ptr;
        }
        TempPtr->next_ptr = NewNode;
    }
}

// void print_list(nodeData * LinkedListHead)
// {
//     nodeData * current = LinkedListHead;

//     while (current != NULL)
//     {
//         printf("Draw Letter: %c \n", current->letter);
//         printf("Draw Command: %s \n", current->drawCommands);
//         current = current->next_ptr;
//     }
// }

void search(nodeData * LinkedListHead, char x, char array[maxSize][maxSize],int printNumber)
{   
    nodeData* current = LinkedListHead;
    char passCommand[maxSize];
    while (current != NULL) 
    { 
        if (current->letter == x) 
        {
            // printf("Search : %s\n", current->drawCommands);
             strcpy(passCommand,current->drawCommands);
            drawLetters(passCommand, array, printNumber);
        }
        current = current->next_ptr; 
    } 

}
