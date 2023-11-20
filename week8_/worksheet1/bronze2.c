#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int holder = 0; 
void multiplyMatrix(int a[2][3], int b[3][2], int c[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] * b[i][1] + a[i][j] * b[i][2] + a[i][j] * b[i][3];
        }
    }
}

//print a 2D array
void printArray(int a[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int A[2][3] = {1, 2, 3, 4, 5, 6};
    int B[3][2] = {1, 2, 3, 4, 5, 6};
    int C[2][2];

    // multiply the two arrays A, B
    multiplyMatrix(A, B, C);



    printf("Array C (result of multiplication):\n");
    printArray(C);

    return 0;
}
