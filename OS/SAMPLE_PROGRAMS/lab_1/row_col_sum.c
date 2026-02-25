#include <stdio.h>

int main() {
    int mat[10][10], r, c, sumR, sumC;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    
    printf("Enter matrix elements: \n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) scanf("%d", &mat[i][j]);

    for(int i = 0; i < r; i++) {
        sumR = 0;
        for(int j = 0; j < c; j++) sumR += mat[i][j];
        printf("Sum of Row %d: %d\n", i+1, sumR);
    }

    for(int j = 0; j < c; j++) {
        sumC = 0;
        for(int i = 0; i < r; i++) sumC += mat[i][j];
        printf("Sum of Column %d: %d\n", j+1, sumC);
    }
    return 0;
}