#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int request[100];
    int head, totalSeek = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++) {
        totalSeek += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d", totalSeek);
    printf("\nAverage Seek Time = %.2f\n", (float)totalSeek / n);

    return 0;
}
