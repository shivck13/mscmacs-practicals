#include <stdio.h>
#include <math.h>

// Function to compute eigenvalues and eigenvectors of 2x2 symmetric matrix
void compute_eigen_2x2(double R[2][2], double eigenvalues[2], double eigenvectors[2][2]) {
    double a = R[0][0];
    double b = R[0][1];
    double d = R[1][1];

    // Characteristic equation: λ^2 - (a + d)λ + (ad - b^2) = 0
    double trace = a + d;
    double det = a * d - b * b;
    double discriminant = sqrt(trace * trace - 4 * det);

    eigenvalues[0] = (trace + discriminant) / 2;
    eigenvalues[1] = (trace - discriminant) / 2;

    // Compute eigenvectors
    for (int i = 0; i < 2; i++) {
        double lambda = eigenvalues[i];
        double v1 = 1.0;
        double v2 = (lambda - a) != 0 ? -b / (lambda - a) : 0;

        double norm = sqrt(v1 * v1 + v2 * v2);
        eigenvectors[0][i] = v1 / norm;
        eigenvectors[1][i] = v2 / norm;
    }
}

int main() {
    double R[2][2] = {
        {1.0, 0.4},
        {0.4, 1.0}
    };

    double eigenvalues[2];
    double eigenvectors[2][2];

    compute_eigen_2x2(R, eigenvalues, eigenvectors);

    // Print eigenvalues
    printf("Eigenvalues (variance explained by each PC):\n");
    for (int i = 0; i < 2; i++) {
        printf("λ%d = %.4f\n", i + 1, eigenvalues[i]);
    }

    // Print eigenvectors
    printf("\nEigenvectors (Principal Component directions):\n");
    for (int i = 0; i < 2; i++) {
        printf("PC%d: [%.4f  %.4f]\n", i + 1, eigenvectors[0][i], eigenvectors[1][i]);
    }

    return 0;
}
