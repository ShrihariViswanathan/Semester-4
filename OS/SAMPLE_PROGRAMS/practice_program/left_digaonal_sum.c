#include <stdio.h>

int main() {
    int mat[10][10], size, sum = 0;
    printf("Enter size of square matrix: ");
    scanf("%d", &size);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
            if(i == j) sum += mat[i][j];
        }
    }
    printf("Sum of left diagonal: %d\n", sum);
    return 0;
}