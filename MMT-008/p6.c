#include <stdio.h>
#include <math.h>

#define N 3

// Compute dot product of two 3D vectors
double dot(double a[], double b[]) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

// Normalize a 3D vector
void normalize(double v[]) {
    double norm = sqrt(dot(v, v));
    for (int i = 0; i < 3; i++)
        v[i] /= norm;
}

// Subtract projection of u onto v
void subtract_projection(double u[], double v[], double result[]) {
    double proj_coeff = dot(u, v);
    for (int i = 0; i < 3; i++)
        result[i] = u[i] - proj_coeff * v[i];
}

int main() {
    double A[3][3];

    // First row with equal elements: 1/sqrt(3)
    for (int i = 0; i < 3; i++)
        A[0][i] = 1.0 / sqrt(3.0);

    // Arbitrary vector not parallel to A[0]: [1, -1, 0]
    double temp1[3] = {1, -1, 0};
    subtract_projection(temp1, A[0], A[1]);
    normalize(A[1]);

    // Another arbitrary vector: [1, 1, -2]
    double temp2[3] = {1, 1, -2};
    subtract_projection(temp2, A[0], temp2);     // Make orthogonal to row 0
    subtract_projection(temp2, A[1], A[2]);      // Make orthogonal to row 1
    normalize(A[2]);

    // Display the orthogonal matrix
    printf("Orthogonal 3x3 matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%8.4f ", A[i][j]);
        printf("\n");
    }

    return 0;
}
