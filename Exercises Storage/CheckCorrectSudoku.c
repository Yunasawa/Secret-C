/*
Description
    A matrix 9 x 9 is called a sudoku solution if it satisfies following constraints
    Each element is an integer from 1 to 9
    Elements on each row are distinct
    Elements on each column are distinct
    Elements on each sub-square 3x3 are distinct (the matrix is divided into 9 distinct subsquares of size 3x3) 

    Write a program that checks whether or not a given matrix is a sudoku solution 
Input
    Line 1: contains a positive integer T which is the number of matrix 9x9
    Subsequent lines are blocks, each block contains a matrix 9x9 with the following format
    Line i (i = 1, 2, ..., 9) contains the i line of the matrix

Output
    Contains T lines, each line i (i = 1, 2, ..., T) contains 1 if the ith matrix is a sudoku solution, and contains 0, otherwise

Example
Input
    2
    1 2 3 4 5 6 7 8 9 
    4 5 6 7 8 9 1 2 3 
    7 8 9 1 2 3 4 5 6 
    2 1 4 3 6 5 8 9 7 
    3 6 5 8 9 7 2 1 4 
    8 9 7 2 1 4 3 6 5 
    5 3 1 6 7 8 9 4 2 
    9 7 2 5 4 1 6 3 8 
    6 4 8 9 3 2 5 7 1 
    1 2 3 4 5 6 7 8 9 
    4 5 6 7 8 9 1 2 3 
    7 8 9 1 2 3 4 5 6 
    2 1 4 3 6 5 8 9 7 
    3 6 5 8 9 7 2 1 4 
    8 9 7 2 1 4 3 6 5 
    5 3 1 6 7 8 9 4 2 
    9 7 8 5 4 2 6 3 1 
    4 4 2 9 3 1 5 7 8 

Output
    1
    0

*/
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool check(int grid[N][N]) 
{
    int row, col, i, j;
    int freq[N + 1];

    // Check rows
    for (row = 0; row < N; row++) 
    {
        for (i = 1; i <= N; i++) 
        {
            freq[i] = 0;
        }
        for (col = 0; col < N; col++) 
        {
            freq[grid[row][col]]++;
        }
        for (i = 1; i <= N; i++) 
        {
            if (freq[i] != 1) 
            {
                return false;
            }
        }
    }

    // Check columns
    for (col = 0; col < N; col++) 
    {
        for (i = 1; i <= N; i++) 
        {
            freq[i] = 0;
        }
        for (row = 0; row < N; row++) 
        {
            freq[grid[row][col]]++;
        }
        for (i = 1; i <= N; i++) 
        {
            if (freq[i] != 1) 
            {
                return false;
            }
        }
    }

    // Check sub-grids
    for (row = 0; row < N; row += 3) 
    {
        for (col = 0; col < N; col += 3) 
        {
            for (i = 1; i <= N; i++) 
            {
                freq[i] = 0;
            }
            for (i = row; i < row + 3; i++) 
            {
                for (j = col; j < col + 3; j++) 
                {
                    freq[grid[i][j]]++;
                }
            }
            for (i = 1; i <= N; i++) 
            {
                if (freq[i] != 1) 
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() 
{
    int T, i, j, k;
    int grid[N][N];

    scanf("%d", &T);
    for (k = 0; k < T; k++) 
    {
        for (i = 0; i < N; i++) 
        {
            for (j = 0; j < N; j++) 
            {
                scanf("%d", &grid[i][j]);
            }
        }
        printf("%d\n", check(grid));
    }

    return 0;
}
