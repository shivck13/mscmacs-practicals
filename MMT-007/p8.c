#include <stdio.h>
#include <math.h>

// Define the function f(x, y) = dy/dx = x^2 + y^3
double f(double x, double y) {
    return x * x + pow(y, 3);
}

// Define y''(x, y) = 2x + 3y^2 * f(x, y)
double y_double_prime(double x, double y) {
    return 2 * x + 3 * y * y * f(x, y);
}

// Second-order Taylor method to compute y_next
double taylor2(double x, double y, double h) {
    return y + h * f(x, y) + (h * h / 2.0) * y_double_prime(x, y);
}

// Milne's Predictor
double predictor(double y_prev3, double f_prev2, double f_prev1, double f_current, double h) {
    return y_prev3 + (4 * h / 3.0) * (2 * f_prev2 - f_prev1 + 2 * f_current);
}

// Milne's Corrector
double corrector(double y_prev1, double f_prev1, double f_current, double f_next, double h) {
    return y_prev1 + (h / 3.0) * (f_prev1 + 4 * f_current + f_next);
}

int main() {
    double x[10], y[10], h = 0.2;
    int i, n = 6;

    // Initial condition
    x[0] = 1.0;
    y[0] = 0.0;

    // Compute x values
    for (i = 1; i <= n; i++) {
        x[i] = x[0] + i * h;
    }

    // Compute y[1] to y[3] using 2nd order Taylor series
    for (i = 0; i < 3; i++) {
        y[i + 1] = taylor2(x[i], y[i], h);
    }

    // Apply Milne's method from i = 3 to i = n - 1
    for (i = 3; i < n; i++) {
        double f_i = f(x[i], y[i]);
        double f_im1 = f(x[i - 1], y[i - 1]);
        double f_im2 = f(x[i - 2], y[i - 2]);
        double f_im3 = f(x[i - 3], y[i - 3]);

        // Predictor
        double y_pred = predictor(y[i - 3], f_im2, f_im1, f_i, h);

        // Corrector (1 iteration)
        double f_next = f(x[i + 1], y_pred);
        y[i + 1] = corrector(y[i - 1], f_im1, f_i, f_next, h);
    }

    // Output the results
    printf("x\t\ty\n");
    for (i = 0; i <= n; i++) {
        printf("%.1f\t\t%.6lf\n", x[i], y[i]);
    }

    return 0;
}
