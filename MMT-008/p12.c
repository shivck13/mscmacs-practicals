#include <stdio.h>
#include <math.h>

#define SIZE 3
#define EPSILON 1e-10
#define MAX_ITER 100

// Function to print matrix
void print_matrix(double A[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) {
            printf("%8.4f ", A[i][j]);
        }
        printf("]\n");
    }
}

// Jacobi method for eigenvalues and eigenvectors
void jacobi(double A[SIZE][SIZE], double eigenvectors[SIZE][SIZE], double eigenvalues[SIZE]) {
    double B[SIZE][SIZE], V[SIZE][SIZE];
    int p, q, i, j, k, iter = 0;
    double t, c, s, tau, theta;
    
    // Copy A to B
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++) {
            B[i][j] = A[i][j];
            V[i][j] = (i == j) ? 1.0 : 0.0;  // Identity
        }

    while (iter++ < MAX_ITER) {
        // Find largest off-diagonal element
        double max = 0.0;
        for (i = 0; i < SIZE; i++) {
            for (j = i + 1; j < SIZE; j++) {
                if (fabs(B[i][j]) > fabs(max)) {
                    max = B[i][j];
                    p = i;
                    q = j;
                }
            }
        }

        if (fabs(max) < EPSILON)
            break;

        theta = (B[q][q] - B[p][p]) / (2.0 * B[p][q]);
        t = (theta >= 0.0) ? (1.0 / (theta + sqrt(theta*theta + 1.0))) 
                           : (-1.0 / (-theta + sqrt(theta*theta + 1.0)));
        c = 1.0 / sqrt(t*t + 1.0);
        s = t * c;
        tau = s / (1.0 + c);

        double temp = B[p][q];
        B[p][q] = 0.0;
        B[p][p] -= t * temp;
        B[q][q] += t * temp;

        for (i = 0; i < SIZE; i++) {
            if (i != p && i != q) {
                double Bip = B[i][p], Biq = B[i][q];
                B[i][p] = Bip - s * (Biq + tau * Bip);
                B[p][i] = B[i][p];
                B[i][q] = Biq + s * (Bip - tau * Biq);
                B[q][i] = B[i][q];
            }
        }

        for (i = 0; i < SIZE; i++) {
            double Vip = V[i][p], Viq = V[i][q];
            V[i][p] = Vip - s * (Viq + tau * Vip);
            V[i][q] = Viq + s * (Vip - tau * Viq);
        }
    }

    // Copy results
    for (i = 0; i < SIZE; i++) {
        eigenvalues[i] = B[i][i];
        for (j = 0; j < SIZE; j++)
            eigenvectors[i][j] = V[i][j];
    }
}

int main() {
    double Sigma[SIZE][SIZE] = {
        {1, -2, 0},
        {-2, 5, 0},
        {0, 0, 2}
    };

    double eigenvectors[SIZE][SIZE];
    double eigenvalues[SIZE];

    jacobi(Sigma, eigenvectors, eigenvalues);

    printf("Eigenvalues (variances of PCs):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("λ%d = %.4f\n", i + 1, eigenvalues[i]);
    }

    printf("\nPrincipal Component Directions (Eigenvectors):\n");
    print_matrix(eigenvectors);

    return 0;
}
