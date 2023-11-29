#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Input from keyboard that ignore 'Space' and 'Enter'. Escape by press 'Enter' two times
char *StringIgnoreEnter()
{
    char *str = (char*)malloc(1000000 * sizeof(char));
    int index = 0;
    int prev = 0;

    while(1)
    {
        char c = getchar();

        if(c == '\n' && prev == c) break;
        str[index++] = c;

        prev = c; 
    }

    return str;
}

// Merge two strings
char *MergeString(const char s1[], const char s2[])
{
    char *merge = (char*)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));

    if (merge == NULL) return NULL;

    for (int i = 0; i < strlen(s1); i++) merge[i] = s1[i];
    for (int i = 0; i < strlen(s2); i++) merge[i + strlen(s2)] = s2[i];
    merge[strlen(s1) + strlen(s2)] = '\0';
    
    return merge;
}

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

// Search of type "Move To Front"
int SearchMTF(char a[], int size, char key)
{
  int i, j;
  char temp;
  for (i = 0; i < size - 1; i++)
  {
    if (key == a[i])
    {
      if (i > 0)
      {
        temp = a[i];
        for (j = i; j > 0; j--) a[j] = a[j-1];
        a[0] = temp;
      }
      return i;
    }
  }
  return -1;
}