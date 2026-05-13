#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m];
    int finish[n], safeSeq[n], ind = 0;

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &max[i][j]);

    printf("Enter Available Resources: ");
    for (i = 0; i < m; i++) scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
        finish[i] = 0;
    }

    // Safety Algorithm
    int work[m];
    for (i = 0; i < m; i++) work[i] = avail[i];

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeSeq[ind++] = i;
                    for (int y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    bool safe = true;
    for(i=0; i<n; i++) if(finish[i] == 0) safe = false;

    if (safe) {
        printf("\nSystem is in SAFE State.\nSafe Sequence: ");
        for (i = 0; i < n - 1; i++) printf("P%d -> ", safeSeq[i]);
        printf("P%d\n", safeSeq[n - 1]);
    } else {
        printf("\nSystem is in DEADLOCK State (Unsafe).\n");
    }


    // --- NEW: Resource Request Section ---
    int p_idx;
    int request[m];
    printf("\nEnter process index making a request (0 to %d): ", n-1);
    scanf("%d", &p_idx);
    printf("Enter request for resources: ");
    for (i = 0; i < m; i++) scanf("%d", &request[i]);

    // Step 1: Check if Request <= Need
    for (i = 0; i < m; i++) {
        if (request[i] > need[p_idx][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return 0;
        }
    }

    // Step 2: Check if Request <= Available
    for (i = 0; i < m; i++) {
        if (request[i] > avail[i]) {
            printf("Resources not available. Process P%d must wait.\n", p_idx);
            return 0;
        }
    }

    // Step 3: Speculative Allocation (Pretend to grant request)
    for (i = 0; i < m; i++) {
        avail[i] -= request[i];
        alloc[p_idx][i] += request[i];
        need[p_idx][i] -= request[i];
    }

    // --- Safety Algorithm (Check if pretend state is safe) ---
    for (i = 0; i < m; i++) work[i] = avail[i];
    for (i = 0; i < n; i++) finish[i] = 0;

    ind = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeSeq[ind++] = i;
                    for (int y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    safe = true;
    for(i=0; i<n; i++) if(finish[i] == 0) safe = false;

    if (safe) {
        printf("\nRequest can be GRANTED safely.\nSafe Sequence: ");
        for (i = 0; i < n - 1; i++) printf("P%d -> ", safeSeq[i]);
        printf("P%d\n", safeSeq[n - 1]);
    } else {
        // Step 4: Rollback if unsafe
        for (i = 0; i < m; i++) {
            avail[i] += request[i];
            alloc[p_idx][i] -= request[i];
            need[p_idx][i] += request[i];
        }
        printf("\nRequest DENIED. Granting it would result in an unsafe state.\n");
    }
    return 0;
}
