#include <stdio.h>

// Function to compute inverse of a 2x2 matrix
void inverse2x2(double A[2][2], double invA[2][2]) {
    double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    if (det == 0) {
        printf("Matrix is singular, cannot invert.\n");
        return;
    }
    invA[0][0] =  A[1][1] / det;
    invA[0][1] = -A[0][1] / det;
    invA[1][0] = -A[1][0] / det;
    invA[1][1] =  A[0][0] / det;
}

// Dot product of two 2D vectors
double dot2(double a[2], double b[2]) {
    return a[0]*b[0] + a[1]*b[1];
}

// Multiply 1x2 * 2x2 → 1x2 result
void mat1x2_mul_2x2(double a[2], double B[2][2], double result[2]) {
    result[0] = a[0]*B[0][0] + a[1]*B[1][0];
    result[1] = a[0]*B[0][1] + a[1]*B[1][1];
}

int main() {
    // Mean vector μ = [μ1, μ2, μ3]
    double mu[3] = {1.0, 2.0, 3.0};

    // Covariance matrix Σ (symmetric and positive definite)
    double Sigma[3][3] = {
        {4.0, 1.0, 2.0},
        {1.0, 3.0, 0.5},
        {2.0, 0.5, 2.0}
    };

    // Observation y2 = 2.5, y3 = 3.5
    double y2 = 2.5, y3 = 3.5;

    // Step 1: Marginals
    printf("Marginal distributions:\n");
    for (int i = 0; i < 3; i++) {
        printf("y%d ~ N(%.2f, %.2f)\n", i+1, mu[i], Sigma[i][i]);
    }

    // Step 2: Conditional distribution y1 | y2, y3
    double mu1 = mu[0];
    double mu23[2] = { mu[1], mu[2] };
    double y23[2] = { y2, y3 };
    double y23_minus_mu23[2] = { y23[0] - mu23[0], y23[1] - mu23[1] };

    double Sigma11 = Sigma[0][0];
    double Sigma12[2] = { Sigma[0][1], Sigma[0][2] };
    double Sigma21[2] = { Sigma[1][0], Sigma[2][0] };
    double Sigma22[2][2] = {
        { Sigma[1][1], Sigma[1][2] },
        { Sigma[2][1], Sigma[2][2] }
    };

    // Compute Σ22⁻¹
    double invSigma22[2][2];
    inverse2x2(Sigma22, invSigma22);

    // Compute Σ12 * Σ22⁻¹ → result is 1x2 vector
    double Sigma12_invSigma22[2];
    mat1x2_mul_2x2(Sigma12, invSigma22, Sigma12_invSigma22);

    // Compute μ_cond = μ1 + Σ12 Σ22⁻¹ (y₂₃ - μ₂₃)
    double mu_cond = mu1 + dot2(Sigma12_invSigma22, y23_minus_mu23);

    // Compute σ²_cond = Σ11 - Σ12 Σ22⁻¹ Σ21
    double sigma2_cond = Sigma11 - dot2(Sigma12_invSigma22, Sigma21);

    printf("\nConditional distribution of y1 | y2=%.2f, y3=%.2f:\n", y2, y3);
    printf("y1 | y2, y3 ~ N(%.4f, %.4f)\n", mu_cond, sigma2_cond);

    return 0;
}