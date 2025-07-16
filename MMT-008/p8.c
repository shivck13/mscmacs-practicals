#include <stdio.h>
#include <math.h>

#define N 100  // max observations

// Function to compute inverse of 2x2 matrix
void inverse2x2(double A[2][2], double inv[2][2]) {
    double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    inv[0][0] = A[1][1] / det;
    inv[0][1] = -A[0][1] / det;
    inv[1][0] = -A[1][0] / det;
    inv[1][1] = A[0][0] / det;
}

// Dot product of 2D vectors
double dot2(double a[2], double b[2]) {
    return a[0]*b[0] + a[1]*b[1];
}

int main() {
    int n;
    printf("Enter number of observations: ");
    scanf("%d", &n);

    double data[N][2], mean[2] = {0}, mu0[2];

    printf("Enter %d observations (x1 x2):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &data[i][0], &data[i][1]);
        mean[0] += data[i][0];
        mean[1] += data[i][1];
    }
    mean[0] /= n;
    mean[1] /= n;

    printf("Enter hypothesized mean vector (mu0): ");
    scanf("%lf%lf", &mu0[0], &mu0[1]);

    // Compute sample covariance matrix (2x2)
    double S[2][2] = {{0}}, diff[2];
    for (int i = 0; i < n; i++) {
        double x1 = data[i][0] - mean[0];
        double x2 = data[i][1] - mean[1];
        S[0][0] += x1 * x1;
        S[0][1] += x1 * x2;
        S[1][0] += x2 * x1;
        S[1][1] += x2 * x2;
    }

    // Divide by (n - 1) to get unbiased estimate
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            S[i][j] /= (n - 1);

    // Compute difference vector (x̄ - mu0)
    diff[0] = mean[0] - mu0[0];
    diff[1] = mean[1] - mu0[1];

    // Compute inverse of S
    double Sinv[2][2];
    inverse2x2(S, Sinv);

    // Compute T² = n * (diff)^T * S⁻¹ * (diff)
    double temp[2];
    temp[0] = Sinv[0][0]*diff[0] + Sinv[0][1]*diff[1];
    temp[1] = Sinv[1][0]*diff[0] + Sinv[1][1]*diff[1];
    double T2 = n * dot2(diff, temp);

    printf("\nHotelling T² statistic: %.4f\n", T2);
    return 0;
}
