#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    int visited[n];   // To track already counted elements
    
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;  // Initialize visited array
    }

    int duplicateCount = 0;

    for(i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;

        int count = 1;

        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        if(count > 1) {
            duplicateCount++;
        }
    }

    printf("Total number of duplicate elements: %d\n", duplicateCount);

    return 0;
}