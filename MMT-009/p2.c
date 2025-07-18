
#include <stdio.h>
#include <math.h>

#define N 18

float x[N] = {
    66.30, 64.84, 64.36,
    69.70, 66.26, 72.06,
    73.23, 71.40, 68.85,
    75.78, 72.57, 76.64,
    78.87, 77.37, 15.94,
    78.82, 77.13, 77.09
};

float y[N] = {
    40, 40, 40,
    45, 45, 45,
    50, 50, 50,
    55, 55, 55,
    60, 60, 60,
    65, 65, 65
};

float calculate_r_squared(float actual[], float predicted[], int n) {
    float mean = 0.0, ss_tot = 0.0, ss_res = 0.0;
    for (int i = 0; i < n; i++) mean += actual[i];
    mean /= n;
    for (int i = 0; i < n; i++) {
        ss_tot += pow(actual[i] - mean, 2);
        ss_res += pow(actual[i] - predicted[i], 2);
    }
    return 1 - (ss_res / ss_tot);
}

int main() {
    // Linear sums
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < N; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    // Linear coefficients
    float b1 = (N * sum_xy - sum_x * sum_y) / (N * sum_x2 - sum_x * sum_x);
    float a1 = (sum_y - b1 * sum_x) / N;

    // Predictions for linear
    float linear_pred[N];
    for (int i = 0; i < N; i++)
        linear_pred[i] = a1 + b1 * x[i];

    float r2_linear = calculate_r_squared(y, linear_pred, N);

    // Quadratic sums
    float sum_x3 = 0, sum_x4 = 0, sum_x2y = 0;
    for (int i = 0; i < N; i++) {
        float xi2 = x[i] * x[i];
        sum_x3 += xi2 * x[i];
        sum_x4 += xi2 * xi2;
        sum_x2y += xi2 * y[i];
    }

    // Build system for quadratic
    float A[3][3] = {
        {N, sum_x, sum_x2},
        {sum_x, sum_x2, sum_x3},
        {sum_x2, sum_x3, sum_x4}
    };
    float B[3] = {sum_y, sum_xy, sum_x2y};

    // Gaussian elimination
    for (int i = 0; i < 3; i++) {
        float diag = A[i][i];
        for (int j = 0; j < 3; j++) A[i][j] /= diag;
        B[i] /= diag;

        for (int k = 0; k < 3; k++) {
            if (k != i) {
                float factor = A[k][i];
                for (int j = 0; j < 3; j++) A[k][j] -= factor * A[i][j];
                B[k] -= factor * B[i];
            }
        }
    }

    float a2 = B[0], b2 = B[1], c2 = B[2];

    // Predictions for quadratic
    float quad_pred[N];
    for (int i = 0; i < N; i++)
        quad_pred[i] = a2 + b2 * x[i] + c2 * x[i] * x[i];

    float r2_quad = calculate_r_squared(y, quad_pred, N);

    // Output
    printf("Linear Fit: y = %.4f + %.4f*x\n", a1, b1);
    printf("R^2 (Linear): %.4f\n\n", r2_linear);

    printf("Quadratic Fit: y = %.4f + %.4f*x + %.6f*x^2\n", a2, b2, c2);
    printf("R^2 (Quadratic): %.4f\n", r2_quad);

    return 0;
}
