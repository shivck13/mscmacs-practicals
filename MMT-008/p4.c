#include <stdio.h>

// Invert a 2x2 matrix using formula:
// A⁻¹ = (1/det) * [ d  -b
//                  -c   a ]
void inverse2x2(double A[2][2], double invA[2][2]) {
    double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    if (det == 0) {
        printf("Matrix is singular!\n");
        return;
    }

    invA[0][0] =  A[1][1] / det;
    invA[0][1] = -A[0][1] / det;
    invA[1][0] = -A[1][0] / det;
    invA[1][1] =  A[0][0] / det;
}

// Dot product: aᵗ * b
double dot2(double a[2], double b[2]) {
    return a[0]*b[0] + a[1]*b[1];
}

// Matrix-vector multiplication: a(1x2) * B(2x2) → result(1x2)
void mat1x2_mul_2x2(double a[2], double B[2][2], double result[2]) {
    result[0] = a[0]*B[0][0] + a[1]*B[1][0];
    result[1] = a[0]*B[0][1] + a[1]*B[1][1];
}

int main() {
    // Given data:
    double Sigma_xx[2][2] = {
        {4.0, 2.0},
        {2.0, 3.0}
    };  // Covariance matrix Σ_xx

    double sigma_xy[2] = {3.0, 2.5}; // Covariance vector σ_xy
    double sigma_yy = 5.0;           // Variance σ_yy

    // Step 1: Compute inverse of Σ_xx
    double inv_Sxx[2][2];
    inverse2x2(Sigma_xx, inv_Sxx);

    // Step 2: Compute temp = σ_xyᵗ * Σ_xx⁻¹
    // This is a row vector: (1x2)
    double temp[2];
    mat1x2_mul_2x2(sigma_xy, inv_Sxx, temp);

    // Step 3: Compute R² using:
    // R² = (σ_xyᵗ * Σ_xx⁻¹ * σ_xy) / σ_yy
    double R_squared = dot2(temp, sigma_xy) / sigma_yy;

    // Step 4: Compute MSE using:
    // MSE = σ_yy * (1 - R²)
    double MSE = sigma_yy * (1 - R_squared);

    // Output results
    printf("Multiple Correlation Coefficient (R^2): %.4f\n", R_squared);
    printf("Mean Square Error (MSE): %.4f\n", MSE);

    return 0;
}