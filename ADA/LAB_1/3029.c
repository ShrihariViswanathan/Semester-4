// Comparator for sorting
int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

char* orderlyQueue(char* s, int k) {
    int n = strlen(s);

    // Case 1: k > 1, we can generate any permutation → just sort
    if (k > 1) {
        qsort(s, n, 1, cmp);
        return s;
    }

    // Case 2: k == 1 → find lexicographically smallest rotation (Booth's algorithm)
    int i = 0, j = 1, k2 = 0;

    while (i < n && j < n && k2 < n) {
        char a = s[(i + k2) % n];
        char b = s[(j + k2) % n];

        if (a == b) {
            k2++;
        } else {
            if (a > b) 
                i = i + k2 + 1;
            else 
                j = j + k2 + 1;

            if (i == j) 
                j++;

            k2 = 0;
        }
    }

    int start = i < j ? i : j;

    // Build the resulting smallest rotation
    char* res = malloc(n + 1);
    for (int t = 0; t < n; t++) {
        res[t] = s[(start + t) % n];
    }
    res[n] = '\0';

    return res;
}
