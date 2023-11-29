/*
Description
    Write a function that gets a string and two chars as arguments. The functions scans the string 
    and replaces every occurrence of the first char with the second one. Write a program to test the 
    above function. The program should read a string from the user (no spaces) and two characters, 
    then call the function with the input, and print the result.
For example
    - input: papa p m
    - output: mama
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Replace characters in a string with another 
char *ReplaceCharacter(const char str[], char a, char b)
{
    char *replace = (char*)malloc((strlen(str) + 1) * sizeof(char));

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != a) replace[i] = str[i];
        else replace[i] = b;
    }
    replace[strlen(str)] = '\0';

    return replace;
}

int main()
{
    char *input, origin, replace;
    input = (char*)malloc(1000 * sizeof(char));
    scanf("%s %c %c", input, &origin, &replace);
    printf("%s", ReplaceCharacter(input, origin, replace));

    free(input);
    return 0;
}