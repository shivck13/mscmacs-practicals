#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 32     // Number of data points
#define M 4      // Number of predictors (x1 to x4)

double y[N] = {
    29,24,26,22,27,21,33,34,32,34,20,36,34,23,24,32,
    40,46,55,52,29,22,31,45,37,37,33,27,34,19,16,22
};

double X[N][M] = {
    {33,53,3.32,3.42},{31,36,3.10,3.26},{33,51,3.18,3.18},{37,51,3.39,3.08},
    {36,54,3.20,3.41},{35,35,3.03,3.03},{59,56,4.78,4.57},{60,60,4.72,4.72},
    {59,60,4.60,4.41},{60,60,4.53,4.53},{34,35,2.90,2.95},{60,59,4.40,4.36},
    {60,62,4.31,4.42},{60,36,4.27,3.94},{62,38,4.41,3.49},{62,61,4.39,4.39},
    {90,64,7.32,6.70},{90,60,7.32,7.20},{92,92,7.45,7.45},{91,92,7.27,7.26},
    {61,62,3.91,4.08},{59,42,3.75,3.45},{88,65,6.48,5.80},{91,89,6.70,6.60},
    {63,62,4.30,6.00},{60,61,4.02,4.10},{60,62,4.02,3.89},{59,62,3.98,4.02},
    {59,62,4.39,4.53},{37,35,2.75,2.64},{35,35,2.59,2.59},{37,37,2.73,2.59}
};

// Function to compute transpose of matrix A[n][m] into AT[m][n]
void transpose(double A[N][M+1], double AT[M+1][N], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            AT[j][i] = A[i][j];
}

// Function to multiply matrices: A[a][b] * B[b][c] = Result[a][c]
void multiply(double A[][N], double B[][M+1], double Result[][M+1], int a, int b, int c) {
    for (int i = 0; i < a; i++)
        for (int j = 0; j < c; j++) {
            Result[i][j] = 0.0;
            for (int k = 0; k < b; k++)
                Result[i][j] += A[i][k] * B[k][j];
        }
}

// Gaussian elimination for solving A*x = B
void gaussian(double A[M+1][M+1], double B[M+1], double x[M+1]) {
    for (int i = 0; i < M+1; i++) {
        // Normalize row
        double diag = A[i][i];
        for (int j = 0; j < M+1; j++)
            A[i][j] /= diag;
        B[i] /= diag;

        // Eliminate
        for (int k = 0; k < M+1; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = 0; j < M+1; j++)
                    A[k][j] -= factor * A[i][j];
                B[k] -= factor * B[i];
            }
        }
    }

    for (int i = 0; i < M+1; i++)
        x[i] = B[i];
}

int main() {
    double X_aug[N][M+1];  // Design matrix with intercept term
    for (int i = 0; i < N; i++) {
        X_aug[i][0] = 1.0;
        for (int j = 1; j <= M; j++)
            X_aug[i][j] = X[i][j-1];
    }

    // Compute X^T * X
    double XT[M+1][N];
    transpose(X_aug, XT, N, M+1);

    double XTX[M+1][M+1];
    multiply(XT, X_aug, XTX, M+1, N, M+1);

    // Compute X^T * y
    double XTy[M+1] = {0};
    for (int i = 0; i < M+1; i++)
        for (int j = 0; j < N; j++)
            XTy[i] += XT[i][j] * y[j];

    // Solve XTX * beta = XTy
    double beta[M+1];
    gaussian(XTX, XTy, beta);

    // Output regression coefficients
    printf("Regression Equation:\n");
    printf("y = %.4f", beta[0]);
    for (int i = 1; i <= M; i++)
        printf(" + %.4f*x%d", beta[i], i);
    printf("\n\n");

    // Compute predictions and residuals
    double y_hat[N], rss = 0.0, tss = 0.0;
    double y_mean = 0.0;
    for (int i = 0; i < N; i++) y_mean += y[i];
    y_mean /= N;

    for (int i = 0; i < N; i++) {
        y_hat[i] = beta[0];
        for (int j = 0; j < M; j++)
            y_hat[i] += beta[j+1] * X[i][j];

        double residual = y[i] - y_hat[i];
        rss += residual * residual;
        tss += (y[i] - y_mean) * (y[i] - y_mean);
    }

    double r2 = 1 - (rss / tss);
    printf("Residual Sum of Squares (RSS): %.4f\n", rss);
    printf("Total Sum of Squares (TSS): %.4f\n", tss);
    printf("R² (Coefficient of Determination): %.4f\n", r2);

    return 0;
}
