#include <stdio.h>
#include <limits.h>

int main() {
    int arr[50], n, first, second;
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    first = second = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] < first) {
            second = first;
            first = arr[i];
        } else if(arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    printf("Second smallest element: %d\n", second);
    return 0;
}