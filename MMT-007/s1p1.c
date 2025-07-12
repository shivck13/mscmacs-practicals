/*
 * @Author: Shiv C Kushawah
 * @Date: 2025-07-12
 * @File: s1p1.c
 * @Description: 
 * @Copyright: © Shiv C Kushawah
 */

#include <stdio.h>

// Define the function f(x, y) = dy/dx here
double f(double x, double y) {
    return x * x - y * y;  // Example: dy/dx = x + y
}

int main() {
    double x0, y0, h, x, y;
    int n;

    // Input initial values
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter number of steps (n): ");
    scanf("%d", &n);

    x = x0;
    y = y0;

    // Euler's method loop
    for (int i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;

        // Output current step result
        printf("After step %d: x = %.5lf, y = %.5lf\n", i + 1, x, y);
    }

    // Final result
    printf("\nApproximate solution at x = %.5lf is y = %.5lf\n", x, y);

    return 0;
}
