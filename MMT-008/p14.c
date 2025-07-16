#include <stdio.h>
#include <math.h>

int main() {
    // Given covariance matrix Σ
    double Sigma[3][3] = {
        {1.0, 0.63, 0.45},
        {0.63, 1.0, 0.35},
        {0.45, 0.35, 1.0}
    };

    double l[3], psi[3];

    // Estimate factor loadings using off-diagonal elements
    // Assume: Σ_12 = l1 * l2, Σ_13 = l1 * l3, Σ_23 = l2 * l3

    // Step 1: Let l1 = 1. Solve others
    l[0] = 1.0;
    l[1] = Sigma[0][1] / l[0]; // l2 = Σ_12 / l1
    l[2] = Sigma[0][2] / l[0]; // l3 = Σ_13 / l1

    // Recalculate l1 using Σ_23 = l2 * l3
    double temp_l1 = Sigma[1][2] / (l[1] * l[2]);
    // Normalize all l's using geometric mean correction
    for (int i = 0; i < 3; i++)
        l[i] *= sqrt(temp_l1);

    // Compute specific variances ψ_i = Σ_ii - l_i^2
    for (int i = 0; i < 3; i++) {
        psi[i] = Sigma[i][i] - l[i] * l[i];
    }

    // Output factor model
    printf("Factor loadings (L):\n");
    for (int i = 0; i < 3; i++) {
        printf("l[%d] = %.4f\n", i + 1, l[i]);
    }

    printf("\nSpecific variances (Psi):\n");
    for (int i = 0; i < 3; i++) {
        printf("ψ[%d] = %.4f\n", i + 1, psi[i]);
    }

    // Reconstruct Σ = LLᵗ + Ψ for verification
    double ReSigma[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ReSigma[i][j] = l[i] * l[j];
            if (i == j) ReSigma[i][j] += psi[i];
        }
    }

    printf("\nReconstructed Σ = LLᵗ + Ψ:\n");
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%.4f ", ReSigma[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
