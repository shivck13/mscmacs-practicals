#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define N 4

// Function to compute transpose
void transpose(double A[N][N], double AT[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            AT[j][i] = A[i][j];
}

// Matrix multiplication: C = A * B
void multiply(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Check if matrix is identity
bool is_identity(double M[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i == j && fabs(M[i][j] - 1.0) > 1e-6)
                return false;
            if (i != j && fabs(M[i][j]) > 1e-6)
                return false;
        }
    return true;
}

// Check if columns are orthonormal
bool check_orthonormal(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        double norm = 0;
        for (int j = 0; j < N; j++)
            norm += A[j][i] * A[j][i];
        if (fabs(norm - 1.0) > 1e-6) return false;

        for (int k = i + 1; k < N; k++) {
            double dot = 0;
            for (int j = 0; j < N; j++)
                dot += A[j][i] * A[j][k];
            if (fabs(dot) > 1e-6) return false;
        }
    }
    return true;
}

int main() {
    double A[N][N] = {
        {0.5, -0.5,  0.5, -0.5},
        {0.5, -0.5, -0.5,  0.5},
        {0.5,  0.5,  0.5,  0.5},
        {0.5,  0.5, -0.5, -0.5}
    };

    double AT[N][N], ATA[N][N];

    transpose(A, AT);
    multiply(AT, A, ATA);

    printf("A^T * A =\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%6.2f ", ATA[i][j]);
        printf("\n");
    }

    if (is_identity(ATA))
        printf("\nMatrix A is ORTHOGONAL (A^T A = I)\n");
    else
        printf("\nMatrix A is NOT orthogonal\n");

    if (check_orthonormal(A))
        printf("Columns of A form an ORTHONORMAL basis of R^4\n");
    else
        printf("Columns of A are NOT orthonormal\n");

    return 0;
}
