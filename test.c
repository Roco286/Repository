#include <stdio.h>
#include <stdlib.h>/*Memory library*/
#include <string.h>/*String library*/
#include <ctype.h> /*char library*/
#define LIST_LENGTH 30
char *lowerStr(char *string);
char *arr[LIST_LENGTH] = {"Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack", "Katherine", "Leo", "Mia", "Nathan", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Tara", "Ulysses", "Victoria", "Walter", "Xena", "Yasmine", "Zane", "Abigail", "Benjamin", "Chloe"};
#define MAX_LENGTH_NAME 21
char publicArray[LIST_LENGTH][MAX_LENGTH_NAME];
int main()
{
    printarray(arr);
}

char *lowerStr(char *string) /*Input char output the char with letters lowercased*/
{
    int i;
    char *lowerCaseStr = malloc(strlen(string) * (sizeof(char)));
    for (i = 0; i < strlen(string); i++)
    {
        lowerCaseStr[i] = tolower(string[i]);
    }
    return lowerCaseStr;
}

int nameCheck(char *newChar, int index) /* Checks if the inputed char already exists inside the array*/
{
    int i;
    for (i = 0; i < index; i++)
    {
        return 0;
    }
    return 1;
}
