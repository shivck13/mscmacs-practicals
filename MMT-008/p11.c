#include <stdio.h>
#include <math.h>

#define K 3  // Number of populations
#define P 2  // Dimension of vector

// Compute dot product of two vectors
double dot(double a[], double b[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i] * b[i];
    return sum;
}

// Matrix-vector multiplication: result = A * x
void matvec(double A[P][P], double x[], double result[]) {
    for (int i = 0; i < P; i++) {
        result[i] = 0;
        for (int j = 0; j < P; j++)
            result[i] += A[i][j] * x[j];
    }
}

// Invert 2x2 matrix
void inverse2x2(double A[P][P], double inv[P][P]) {
    double det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    inv[0][0] =  A[1][1] / det;
    inv[0][1] = -A[0][1] / det;
    inv[1][0] = -A[1][0] / det;
    inv[1][1] =  A[0][0] / det;
}

int main() {
    double mu[K][P];        // Means of 3 populations
    double Sigma[P][P];     // Common covariance matrix
    double SigmaInv[P][P];  // Inverse of Sigma
    double x[P];            // Observation to classify
    double prior[K];        // Prior probabilities

    // Input means
    printf("Enter means (mu_j) for %d populations (2D each):\n", K);
    for (int j = 0; j < K; j++) {
        printf("Population %d: ", j + 1);
        scanf("%lf%lf", &mu[j][0], &mu[j][1]);
    }

    // Input common covariance matrix
    printf("Enter 2x2 common covariance matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < P; j++)
            scanf("%lf", &Sigma[i][j]);

    // Invert covariance matrix
    inverse2x2(Sigma, SigmaInv);

    // Input prior probabilities
    printf("Enter prior probabilities for each population:\n");
    for (int j = 0; j < K; j++) {
        printf("P%d: ", j + 1);
        scanf("%lf", &prior[j]);
    }

    // Input observation to classify
    printf("Enter observation (2D) to classify: ");
    scanf("%lf%lf", &x[0], &x[1]);

    // Compute discriminant scores
    double g[K];
    for (int j = 0; j < K; j++) {
        double temp1[P], temp2[P];

        matvec(SigmaInv, mu[j], temp1);             // Σ⁻¹ * μ_j
        double part1 = dot(x, temp1, P);             // xᵀ Σ⁻¹ μ_j
        double part2 = dot(mu[j], temp1, P);         // μ_jᵀ Σ⁻¹ μ_j
        double part3 = log(prior[j]);                // ln(P_j)

        g[j] = part1 - 0.5 * part2 + part3;
    }

    // Find max score
    int maxClass = 0;
    for (int j = 1; j < K; j++)
        if (g[j] > g[maxClass])
            maxClass = j;

    // Output results
    printf("\nDiscriminant scores:\n");
    for (int j = 0; j < K; j++)
        printf("g[%d] = %.4f\n", j + 1, g[j]);

    printf("\n=> Classified to Population %d\n", maxClass + 1);
    return 0;
}
