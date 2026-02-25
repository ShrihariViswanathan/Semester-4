#include <stdio.h>
#include <limits.h>

int main() {
    int arr[100], n, max1, max2;
    max1 = max2 = INT_MIN;

    printf("Enter size: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if(arr[i] > max2 && arr[i] < max1) {
            max2 = arr[i];
        }
    }
    printf("Second largest: %d\n", max2);
    return 0;
}