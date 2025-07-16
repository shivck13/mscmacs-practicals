#include <stdio.h>
#include <math.h>

#define N 3

void cholesky(double A[N][N], double L[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0.0;

            for (int k = 0; k < j; k++)
                sum += L[i][k] * L[j][k];

            if (i == j)
                L[i][j] = sqrt(A[i][i] - sum);  // Diagonal
            else
                L[i][j] = (A[i][j] - sum) / L[j][j];  // Off-diagonal
        }
    }
}

void print_matrix(double M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%8.4f ", M[i][j]);
        printf("\n");
    }
}

int main() {
    double A[N][N] = {
        { 25, 15, -5 },
        { 15, 18,  0 },
        { -5,  0, 11 }
    };

    double L[N][N] = {0};

    printf("Matrix A:\n");
    print_matrix(A);

    cholesky(A, L);

    printf("\nLower Triangular Matrix L (A = L * Lᵗ):\n");
    print_matrix(L);

    return 0;
}