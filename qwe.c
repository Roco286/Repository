#include <stdio.h>
#include <stdlib.h>/*Memory library*/
#include <string.h>/*String library*/
#include <ctype.h> /*char library*/
#pragma warning(disable : 4996)
#define LIST_LENGTH 5      /* The length of nameList*/
#define MAX_LENGTH_NAME 21 /* Max length of chars in nameList,20 chars + \0*/
char publicArray[LIST_LENGTH][MAX_LENGTH_NAME];

char *get_name();
char *lowerStr(char *string);
int nameCheck(char *newChar, int index);

int main()
{
    int i = 0;
    char nameInput[MAX_LENGTH_NAME];
    printf("Please start enterting names: ");
    /*Enter the inputed names into publicArray*/
    while ((i < LIST_LENGTH)) /*Using while instead of for since i++ only when inputed a valid name*/
    {
        if (scanf("%s", nameInput))
        {
            if (nameCheck(lowerStr(nameInput), i))
            {
                strcpy(publicArray[i], nameInput);
                i++;
            }
            else
            {
                printf("ERROR the name has been inputed already\n");
                return 0; /*Ends the program*/
            }
        }
    } /*End*/

    /*Prints Inputed names*/
    printf("The names Entered are: \n");
    for (i = 0; i < LIST_LENGTH; i++)
    {
        printf("%d) %s\n", i + 1, publicArray[i]);
    } /*End*/

    /*Prints 10 random names from publicArray*/
    printf("10 random names: ");
    for (i = 0; i < 10; i++)
    {
        printf("%s\t", get_name());
    }
    putchar("\n");
    /*End*/
    return 0;
}

char *get_name() /* The function randomly picks name from publicArray*/
{
    int randNumIndex = rand() % (LIST_LENGTH - 1); /*This makes it so the rand number is between 0 - 29*/
    return publicArray[randNumIndex];
}

char *lowerStr(char *string) /*Input char output the char with letters lowercased*/
{
    int i;
    char lowerCaseStr[strlen(string)];
    for (i = 0; i < strlen(string); i++)
    {
        lowerCaseStr[i] = tolower(string[i]);
    }
    return lowerCaseStr; /*Returns the lower cased string*/
}

int nameCheck(char *newChar, int index) /* Checks if the inputed char already exists inside the array*/
{
    int i;
    for (i = 0; i < index; i++)
    {
        if (strcmp(lowerStr(publicArray[i]), newChar) == 0) /*Checks if the inputed string already exists in the array*/
            return 0;                                       /*Returns false - 0*/
    }
    return 1;
}