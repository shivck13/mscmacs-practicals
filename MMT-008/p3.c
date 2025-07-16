#include <stdio.h>

int main() {
    double X[5][3], Y[5], XT[3][5], XTX[3][3], XTY[3], inv[3][3], beta[3];
    
    // Input: 5 rows of (X1, X2, Y)
    printf("Input: 5 rows of (X1, X2, Y)\n");
    for (int i = 0; i < 5; i++) {
        double x1, x2, y;
        scanf("%lf%lf%lf", &x1, &x2, &y);
        X[i][0] = 1; X[i][1] = x1; X[i][2] = x2; Y[i] = y;
        XT[0][i] = 1; XT[1][i] = x1; XT[2][i] = x2;
    }

    // Compute X^T X
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
        for (int k = 0; k < 5; k++) XTX[i][j] += XT[i][k] * X[k][j];

    // Compute X^T Y
    for (int i = 0; i < 3; i++) for (int k = 0; k < 5; k++)
        XTY[i] += XT[i][k] * Y[k];

    // Inverse of 3x3 matrix (XTX)
    double d = XTX[0][0]*(XTX[1][1]*XTX[2][2] - XTX[1][2]*XTX[2][1])
             - XTX[0][1]*(XTX[1][0]*XTX[2][2] - XTX[1][2]*XTX[2][0])
             + XTX[0][2]*(XTX[1][0]*XTX[2][1] - XTX[1][1]*XTX[2][0]);

    double a[3][3] = {
        {XTX[1][1]*XTX[2][2] - XTX[1][2]*XTX[2][1], XTX[0][2]*XTX[2][1] - XTX[0][1]*XTX[2][2], XTX[0][1]*XTX[1][2] - XTX[0][2]*XTX[1][1]},
        {XTX[1][2]*XTX[2][0] - XTX[1][0]*XTX[2][2], XTX[0][0]*XTX[2][2] - XTX[0][2]*XTX[2][0], XTX[0][2]*XTX[1][0] - XTX[0][0]*XTX[1][2]},
        {XTX[1][0]*XTX[2][1] - XTX[1][1]*XTX[2][0], XTX[0][1]*XTX[2][0] - XTX[0][0]*XTX[2][1], XTX[0][0]*XTX[1][1] - XTX[0][1]*XTX[1][0]}
    };
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
        inv[i][j] = a[i][j] / d;

    // beta = (XTX)^-1 * XTY
    for (int i = 0; i < 3; i++) {
        beta[i] = 0;
        for (int j = 0; j < 3; j++)
            beta[i] += inv[i][j] * XTY[j];
    }

    printf("b0 = %.4f\nb1 = %.4f\nb2 = %.4f\n", beta[0], beta[1], beta[2]);
    return 0;
}