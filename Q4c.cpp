#include<stdio.h>
int main() {
    int r, c;
    printf("Enter number of rows and columns of the matrix");
    scanf("%d%d",&r,&c);

    int A[10][10], T[10][10];

    // initial matrix input 
    printf("Enter elements of the matrix: " );
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d",& A[i][j]);
        }
    }

    // Transpose logic (swap rows and columns)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            T[j][i] = A[i][j];
        }
    }

    // Displaying transpose matrix 
    printf( "Transpose of the matrix: " );
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d",T[i][j]);
        }
        printf("\n");
    }

    return 0;
}

