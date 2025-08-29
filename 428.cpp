#include <stdio.h>
#include <stdlib.h>

int celebrity(int **mat, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (mat[j][i] == 1)
            j--;
        else
            i++;
    }
    int c = i;
    for (i = 0; i < n; i++) {
        if (i == c)
            continue;
        if (mat[c][i] || !mat[i][c])
            return -1;
    }
    return c;
}
