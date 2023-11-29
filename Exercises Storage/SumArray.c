/*
Description
    Given a sequence of n integers a1, ..., an. Compute the sum of elements
    Input
    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line 2: contains n integers a1, a2, ..., an (elements are separated by a SPACE character)
Output
    Write the sum of elements of the given sequence.

Example
Input
    4
    1 2 3 4
Output
    10
*/

#include <stdio.h>

#define MAX_LENGTH 100000

int main() 
{
    int n, a[MAX_LENGTH], sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("%d", sum);
    return 0;
}
