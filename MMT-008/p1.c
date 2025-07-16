/*
 * Program: Cholesky Decomposition - Lower Triangular Square Root of a PD Matrix
 * Author: [Your Name]
 * Date: [Insert Date]
 *
 * Description:
 * ------------
 * This program computes the **lower triangular square root** of a
 * **symmetric positive definite (PD)** matrix using **Cholesky Decomposition**.
 *
 * For a PD matrix A, there exists a unique lower triangular matrix L such that:
 *       A = L * Lᵀ
 * Here, L is called the **Cholesky factor**, and is considered the "matrix square root".
 *
 * This decomposition is useful in numerical methods, solving linear systems,
 * Monte Carlo simulations, and optimization problems.
 *
 * The input matrix A must be:
 *   - Real
 *   - Symmetric (A = Aᵀ)
 *   - Positive definite (all eigenvalues > 0)
 */

#include <stdio.h>
#include <math.h>

#define N 3  // Size of the matrix

// Function to perform Cholesky decomposition
int choleskyDecomposition(double A[N][N], double L[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            if (j == i) {  // Diagonal elements
                for (int k = 0; k < j; k++)
                    sum += L[j][k] * L[j][k];
                double diff = A[j][j] - sum;
                if (diff <= 0)
                    return 0; // Not positive definite
                L[j][j] = sqrt(diff);
            } else {
                for (int k = 0; k < j; k++)
                    sum += L[i][k] * L[j][k];
                if (L[j][j] == 0)
                    return 0; // Division by zero
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
    return 1; // Success
}

// Function to print a matrix
void printMatrix(double M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.4f ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example 3x3 symmetric positive definite matrix
    double A[N][N] = {
        {25, 15, -5},
        {15, 18,  0},
        {-5,  0, 11}
    };

    double L[N][N] = {0};  // Lower triangular matrix

    if (choleskyDecomposition(A, L)) {
        printf("Lower Triangular Square Root (Cholesky Factor L):\n");
        printMatrix(L);
    } else {
        printf("Matrix is not positive definite or decomposition failed.\n");
    }

    return 0;
}
