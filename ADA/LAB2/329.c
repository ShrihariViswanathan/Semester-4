int dfs(int** matrix, int rows, int cols, int i, int j, int** dp) {
    if (dp[i][j] != 0)
        return dp[i][j];

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int maxLen = 1;

    for (int d = 0; d < 4; d++) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];

        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
            matrix[ni][nj] > matrix[i][j]) {

            int len = 1 + dfs(matrix, rows, cols, ni, nj, dp);
            if (len > maxLen)
                maxLen = len;
        }
    }

    dp[i][j] = maxLen;
    return maxLen;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {

    if (matrixSize == 0) return 0;

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)calloc(cols, sizeof(int));
    }

    int result = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            int len = dfs(matrix, rows, cols, i, j, dp);
            if (len > result)
                result = len;
        }
    }

    for (int i = 0; i < rows; i++)
        free(dp[i]);
    free(dp);

    return result;
}

SAME LIKE THAT GIVE FOR THIS CODE ALSO
