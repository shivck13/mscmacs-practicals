/*
 * @Author: Shiv C Kushawah
 * @Date: 2025-07-12
 * @File: p4.c
 * @Description: 
 * @Copyright: © Shiv C Kushawah
 */

 #include <stdio.h>

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x * (y - x);  // Example: dy/dx = x + y
}

int main() {
    double x, y, x0, y0, h;
    int n;

    // Input initial conditions and step info
    printf("Enter initial value x0: ");
    scanf("%lf", &x0);
    printf("Enter initial value y0: ");
    scanf("%lf", &y0);
    printf("Enter step size h: ");
    scanf("%lf", &h);
    printf("Enter number of steps n: ");
    scanf("%d", &n);

    x = x0;
    y = y0;

    for (int i = 0; i < n; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h/2, y + h*k1/2);
        double k3 = f(x + h/2, y + h*k2/2);
        double k4 = f(x + h, y + h*k3);

        y = y + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
        x = x + h;

        printf("After step %d: x = %.5lf, y = %.5lf\n", i + 1, x, y);
    }

    printf("\nApproximate solution at x = %.5lf is y = %.5lf\n", x, y);
    return 0;
}
