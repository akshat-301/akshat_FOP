#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrices(int n, int m, int A[10][10], int B[10][10], int C[10][10]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to find saddle point
void saddlePoint(int n, int m, int A[10][10]) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        int minRow = A[i][0], colIndex = 0;
        for (int j = 1; j < m; j++) {
            if (A[i][j] < minRow) {
                minRow = A[i][j];
                colIndex = j;
            }
        }
        int k;
        for (k = 0; k < n; k++) {
            if (A[k][colIndex] > minRow)
                break;
        }
        if (k == n) {
            printf("Saddle point at A[%d][%d] = %d\n", i, colIndex, minRow);
            found = 1;
        }
    }
    if (!found)
        printf("No saddle point found.\n");
}

// Function to calculate determinant
float determinant(float A[10][10], int n) {
    float det = 0;
    if (n == 1)
        return A[0][0];
    float temp[10][10];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == f)
                    continue;
                temp[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
        }
        det += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

// Function to find inverse of matrix
void inverseMatrix(float A[10][10], int n) {
    float det = determinant(A, n);
    if (det == 0) {
        printf("Inverse not possible, determinant is 0.\n");
        return;
    }
    float adj[10][10], inv[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float temp[10][10];
            int subi = 0;
            for (int x = 0; x < n; x++) {
                if (x == i) continue;
                int subj = 0;
                for (int y = 0; y < n; y++) {
                    if (y == j) continue;
                    temp[subi][subj] = A[x][y];
                    subj++;
                }
                subi++;
            }
            float sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = adj[i][j] / det;
            printf("%0.2f\t", inv[i][j]);
        }
        printf("\n");
    }
}

// Function to check magic square
void magicSquare(int n, int A[10][10]) {
    int sumd1 = 0, sumd2 = 0;
    for (int i = 0; i < n; i++) {
        sumd1 += A[i][i];
        sumd2 += A[i][n - i - 1];
    }
    if (sumd1 != sumd2) {
        printf("Not a magic square.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += A[i][j];
            colSum += A[j][i];
        }
        if (rowSum != sumd1 || colSum != sumd1) {
            printf("Not a magic square.\n");
            return;
        }
    }
    printf("It is a magic square!\n");
}

int main() {
    int n, m;
    int A[10][10], B[10][10], C[10][10];
    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    printf("\nMatrix Addition:\n");
    addMatrices(n, m, A, B, C);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    printf("\nSaddle Point:\n");
    saddlePoint(n, m, A);

    if (n == m) {
        printf("\nInverse of Matrix A:\n");
        float Af[10][10];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                Af[i][j] = A[i][j];
        inverseMatrix(Af, n);

        printf("\nMagic Square Check:\n");
        magicSquare(n, A);
    } else {
        printf("\nInverse and Magic Square only possible for square matrices.\n");
    }

    return 0;
}
