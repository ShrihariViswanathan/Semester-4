#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m], finish[n], work[m];

    printf("Enter Allocation Matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++) scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++) scanf("%d", &request[i][j]);

    printf("Enter Available Resources: ");
    for(i=0; i<m; i++) {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    for(i=0; i<n; i++) finish[i] = 0;

    // Detection Algorithm
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) {
            if(finish[i] == 0) {
                int canBeDone = 1;
                for(j=0; j<m; j++) {
                    if(request[i][j] > work[j]) {
                        canBeDone = 0;
                        break;
                    }
                }
                if(canBeDone) {
                    for(j=0; j<m; j++) work[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
    }

    int deadlocked[n], count = 0;
    for(i=0; i<n; i++) {
        if(finish[i] == 0) {
            deadlocked[count++] = i;
        }
    }

    if(count > 0) {
        printf("\nSystem is in DEADLOCK! Deadlocked processes: ");
        for(i=0; i<count; i++) printf("P%d ", deadlocked[i]);
        printf("\n");
    } else {
        printf("\nNo Deadlock Detected.\n");
    }

    return 0;
}
