/*
Description
    Given a chess board N x N on which there are N being placed in N different cells. 
    Write a program that check if there are two queen, that attacks each other.

    A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.
Input
    Line 1: contains a positive integer T which is the number of test-cases (1 <= T <= 100)
    T following block, each block is the input of a test-case with the format:
    Line 1: contains a positive integer N (1 <= N <= 100)
    Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
Output
    In each line t (t = 1, 2, ..., T), write 1 if in the test-case t, there are no two queen that attack each other, and write 0, otherwise 
Example
Input
    2
    4
    0 1 0 0
    0 0 0 1
    1 0 0 0
    0 0 1 0
    4
    0 1 0 0
    0 0 0 0
    1 0 0 1
    0 0 1 0
Output
    1
    0
*/

#include <stdio.h>

int main() {
    int T, N, i, j, k, l, flag;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int A[N][N];
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        flag = 1;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (A[i][j] == 1) {
                    for (k = 0; k < N; k++) {
                        if (A[i][k] == 1 && k != j) {
                            flag = 0;
                            break;
                        }
                        if (A[k][j] == 1 && k != i) {
                            flag = 0;
                            break;
                        }
                        for (l = 1; l < N; l++) {
                            if (i + l < N && j + l < N && A[i + l][j + l] == 1) {
                                flag = 0;
                                break;
                            }
                            if (i - l >= 0 && j - l >= 0 && A[i - l][j - l] == 1) {
                                flag = 0;
                                break;
                            }
                            if (i + l < N && j - l >= 0 && A[i + l][j - l] == 1) {
                                flag = 0;
                                break;
                            }
                            if (i - l >= 0 && j + l < N && A[i - l][j + l] == 1) {
                                flag = 0;
                                break;
                            }
                        }
                        if (flag == 0) {
                            break;
                        }
                    }
                }
                if (flag == 0) {
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        printf("%d\n", flag);
    }
    return 0;
}
