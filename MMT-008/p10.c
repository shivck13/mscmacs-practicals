#include <stdio.h>
#include <math.h>

#define MAX 100

// Compute determinant of 2x2 matrix
double determinant2x2(double A[2][2]) {
    return A[0][0]*A[1][1] - A[0][1]*A[1][0];
}

// Invert a 2x2 matrix
void inverse2x2(double A[2][2], double inv[2][2]) {
    double det = determinant2x2(A);
    inv[0][0] =  A[1][1] / det;
    inv[0][1] = -A[0][1] / det;
    inv[1][0] = -A[1][0] / det;
    inv[1][1] =  A[0][0] / det;
}

// Trace of 2x2 matrix product: trace(A * B)
double trace_product(double A[2][2], double B[2][2]) {
    return A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[1][0]*B[0][1] + A[1][1]*B[1][1];
}

int main() {
    int n;
    double data[MAX][2], mean[2] = {0};

    printf("Enter number of observations: ");
    scanf("%d", &n);

    printf("Enter %d observations (x1 x2):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &data[i][0], &data[i][1]);
        mean[0] += data[i][0];
        mean[1] += data[i][1];
    }

    mean[0] /= n;
    mean[1] /= n;

    // Compute sample covariance matrix S
    double S[2][2] = {{0}};
    for (int i = 0; i < n; i++) {
        double dx = data[i][0] - mean[0];
        double dy = data[i][1] - mean[1];
        S[0][0] += dx * dx;
        S[0][1] += dx * dy;
        S[1][0] += dy * dx;
        S[1][1] += dy * dy;
    }

    // Unbiased estimator
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            S[i][j] /= (n - 1);

    // Input hypothesized covariance matrix Σ₀
    double Sigma0[2][2];
    printf("Enter hypothesized covariance matrix (2x2):\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%lf", &Sigma0[i][j]);

    // Calculate determinants
    double detS = determinant2x2(S);
    double detSigma0 = determinant2x2(Sigma0);

    // Calculate Σ₀⁻¹
    double Sigma0_inv[2][2];
    inverse2x2(Sigma0, Sigma0_inv);

    // Compute trace(Σ₀⁻¹ S)
    double tr = trace_product(Sigma0_inv, S);

    // Compute the likelihood ratio statistic
    int p = 2;
    double L = n * (tr - log(detSigma0 / detS) - p);

    // Degrees of freedom = p(p+1)/2
    int df = p * (p + 1) / 2;

    printf("\nSample covariance matrix S:\n");
    for (int i = 0; i < 2; i++)
        printf("[%.4f %.4f]\n", S[i][0], S[i][1]);

    printf("\n-2 * log Lambda = %.4f\n", L);
    printf("Approximate Chi-Square distribution with %d degrees of freedom\n", df);

    return 0;
}
