#include <stdio.h>
#include <math.h>

#define MAX 100

// Inverse of 2x2 matrix
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
    int n1, n2;
    double x1[MAX][2], x2[MAX][2];
    double mean1[2] = {0}, mean2[2] = {0};

    printf("Enter size of sample 1: ");
    scanf("%d", &n1);
    printf("Enter %d observations for sample 1 (x1 x2):\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%lf%lf", &x1[i][0], &x1[i][1]);
        mean1[0] += x1[i][0];
        mean1[1] += x1[i][1];
    }
    mean1[0] /= n1;
    mean1[1] /= n1;

    printf("Enter size of sample 2: ");
    scanf("%d", &n2);
    printf("Enter %d observations for sample 2 (x1 x2):\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%lf%lf", &x2[i][0], &x2[i][1]);
        mean2[0] += x2[i][0];
        mean2[1] += x2[i][1];
    }
    mean2[0] /= n2;
    mean2[1] /= n2;

    // Sample covariance matrices
    double S1[2][2] = {{0}}, S2[2][2] = {{0}};
    for (int i = 0; i < n1; i++) {
        double dx = x1[i][0] - mean1[0];
        double dy = x1[i][1] - mean1[1];
        S1[0][0] += dx * dx;
        S1[0][1] += dx * dy;
        S1[1][0] += dy * dx;
        S1[1][1] += dy * dy;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            S1[i][j] /= (n1 - 1);

    for (int i = 0; i < n2; i++) {
        double dx = x2[i][0] - mean2[0];
        double dy = x2[i][1] - mean2[1];
        S2[0][0] += dx * dx;
        S2[0][1] += dx * dy;
        S2[1][0] += dy * dx;
        S2[1][1] += dy * dy;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            S2[i][j] /= (n2 - 1);

    // Pooled covariance matrix
    double Sp[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            Sp[i][j] = ((n1 - 1)*S1[i][j] + (n2 - 1)*S2[i][j]) / (n1 + n2 - 2);

    // Difference in mean vectors
    double d[2] = {mean1[0] - mean2[0], mean1[1] - mean2[1]};

    // Inverse of pooled covariance
    double Sp_inv[2][2];
    inverse2x2(Sp, Sp_inv);

    // Compute T^2
    double temp[2];
    temp[0] = Sp_inv[0][0]*d[0] + Sp_inv[0][1]*d[1];
    temp[1] = Sp_inv[1][0]*d[0] + Sp_inv[1][1]*d[1];

    double T2 = (double)(n1 * n2) / (n1 + n2) * dot2(d, temp);

    // Convert to F-statistic
    int p = 2;
    double F = (T2 * (n1 + n2 - p - 1)) / ((n1 + n2 - 2) * p);

    printf("\nHotelling's T² statistic = %.4f\n", T2);
    printf("Equivalent F-statistic = %.4f\n", F);
    printf("Degrees of freedom: (%d, %d)\n", p, n1 + n2 - p - 1);

    return 0;
}
