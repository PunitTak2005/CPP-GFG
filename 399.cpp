int balanceSum(int n, int mat[][n]) {
    int maxSum = 0;
    int res = 0;

    // Compute sum of each row and find the maximum
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
        }
        if (rowSum > maxSum)
            maxSum = rowSum;
    }

    // Compute sum of each column and find the maximum
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += mat[i][j];
        }
        if (colSum > maxSum)
            maxSum = colSum;
    }

    // Total operations = sum of differences between maxSum and each row sum
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
        }
        res += (maxSum - rowSum);
    }

    return res;
}
