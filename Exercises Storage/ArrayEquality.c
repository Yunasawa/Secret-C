/*
Description
    Given two sequence a=a1,…,an and b=b1,…,bm. Check if these sequences are equal.
Input
    Line 1: contains a positive integer T (1≤T≤10^2) represents number of tests
    Follow are T tests, each of which has the following format
    Line 1: n and m (1≤n,m≤1000)
    Line 2: a1,…,an
    Line 3: b1,…,bm
Output
    Write to stdout T lines, each line t contains 1 if the sequences of the t test are equal, and write 0, otherwise.
Example
Input
    3
    3 3
    1 2 3
    1 2 3
    4 2
    1 2 3 4
    1 2
    3 3
    2 4 1
    2 3 1
Output
    1
    0
    0
*/

#include <stdio.h>
#include <stdbool.h>

bool isEqual(int a[], int n, int b[], int m) {
    int i;
    if (n != m) {
        return false;
    }
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int T, i, j, n, m;
    int a[1000], b[1000];

    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d %d", &n, &m);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        for (j = 0; j < m; j++) {
            scanf("%d", &b[j]);
        }
        printf("%d\n", isEqual(a, n, b, m));
    }

    return 0;
}
