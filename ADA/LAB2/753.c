void dfs(int node, int k, int mod, int *visited, char *result, int *idx) {
    for (int i = 0; i < k; i++) {
        int edge = node * k + i;

        if (!visited[edge]) {
            visited[edge] = 1;

            int next = edge % mod;

            dfs(next, k, mod, visited, result, idx);

            result[(*idx)++] = '0' + i;
        }
    }
}

char* crackSafe(int n, int k) {
    int totalEdges = pow(k, n);
    int mod = pow(k, n - 1);

    int *visited = calloc(totalEdges, sizeof(int));

    char *result = malloc(totalEdges + n);
    int idx = 0;

    dfs(0, k, mod, visited, result, &idx);

    for (int i = 0; i < n - 1; i++)
        result[idx++] = '0';

    result[idx] = '\0';

    free(visited);
    return result;
}
