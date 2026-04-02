#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrices(int n, int m, int A[n][m], int B[n][m], int C[n][m]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to find saddle point
void saddlePoint(int n, int m, int A[n][m]) {
    int found = 0;
    for(int i=0; i<n; i++) {
        int minRow = A[i][0], colIndex = 0;
        for(int j=1; j<m; j++) {
            if(A[i][j] < minRow) {
                minRow = A[i][j];
                colIndex = j;
            }
        }
        int k;
        for(k=0; k<n; k++) {
            if(A[k][colIndex] > minRow) break;
        }
        if(k == n) {
            printf("Saddle point at (%d,%d) = %d\n", i, colIndex, minRow);
            found = 1;
        }
    }
    if(!found) printf("No saddle point found.\n");
}

// Function to calculate inverse (for 2x2 matrix only for simplicity)
void inverseMatrix(int A[2][2]) {
    int det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    if(det == 0) {
        printf("Inverse not possible (determinant = 0).\n");
        return;
    }
    printf("Inverse matrix:\n");
    printf("%f %f\n", (float)A[1][1]/det, (float)-A[0][1]/det);
    printf("%f %f\n", (float)-A[1][0]/det, (float)A[0][0]/det);
}

// Function to generate magic square (odd order only)
void magicSquare(int n) {
    int magic[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            magic[i][j] = 0;

    int i = 0, j = n/2;
    for(int num=1; num<=n*n; ) {
        if(i<0 && j==n) {
            i += 2;
            j--;
        } else {
            if(i<0) i = n-1;
            if(j==n) j = 0;
        }
        if(magic[i][j] != 0) {
            i += 2;
            j--;
            continue;
        } else {
            magic[i][j] = num++;
        }
        i--; j++;
    }

    printf("Magic Square of size %d:\n", n);
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            printf("%3d ", magic[r][c]);
        }
        printf("\n");
    }
}

int main() {
    int A[2][2] = {{1,2},{3,4}};
    int B[2][2] = {{5,6},{7,8}};
    int C[2][2];

    printf("Matrix Addition:\n");
    addMatrices(2,2,A,B,C);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++) printf("%d ", C[i][j]);
        printf("\n");
    }

    printf("\nSaddle Point:\n");
    int D[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    saddlePoint(3,3,D);

    printf("\nInverse of Matrix A:\n");
    inverseMatrix(A);

    printf("\nMagic Square:\n");
    magicSquare(3);

    return 0;
}

