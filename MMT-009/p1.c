#include <stdio.h>

int main() {
    // x: energy consumption in KWH
    double x[] = {
        679, 292, 1012, 493, 582, 1156, 997, 2189, 1097, 2078,
        1818, 1700, 747, 2030, 1643, 414, 354, 1276, 745, 435,
        540, 874, 1543, 1029, 710, 1434, 837, 1748, 1381, 1428,
        1255, 1777, 370, 2316, 1130, 463, 770, 724, 808, 790,
        783, 406, 1242, 658, 1746, 468, 1114, 413, 1787, 3560,
        1495, 2221, 1526
    };

    // y: energy demand in KW
    double y[] = {
        0.79, 0.44, 0.56, 0.79, 2.7, 3.64, 4.73, 9.5, 5.34, 6.85,
        5.84, 5.21, 3.25, 4.43, 3.16, 0.5, 0.17, 1.88, 0.77, 1.39,
        0.56, 1.56, 5.28, 0.64, 4.0, 0.31, 4.2, 4.88, 3.48, 7.58,
        2.63, 4.99, 0.59, 8.19, 4.79, 0.51, 1.74, 4.1, 3.94, 0.96,
        3.29, 0.44, 3.24, 2.14, 5.71, 0.64, 1.9, 0.51, 8.33, 14.94,
        5.11, 3.85, 3.93
    };
    int n = sizeof(x) / sizeof(x[0]);

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double c = (sum_y - m * sum_x) / n;

    double y_pred = m * 2050 + c;

    double mean_y = sum_y / n;
    double ss_tot = 0, ss_reg = 0;
    for (int i = 0; i < n; i++) {
        double y_fit = m * x[i] + c;
        ss_tot += (y[i] - mean_y) * (y[i] - mean_y);
        ss_reg += (y_fit - mean_y) * (y_fit - mean_y);
    }

    double r2 = ss_reg / ss_tot;

    printf("Linear model: y = %.4f * x + %.4f\n", m, c);
    printf("Estimated demand for 2050 KWH: %.4f KW\n", y_pred);
    printf("R² using direct formula: %.4f\n", r2);

    return 0;
}
