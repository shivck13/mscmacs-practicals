#include <stdio.h>
#include <math.h>

// Factorial function
double factorial(int n) {
    if (n == 0) return 1.0;
    double result = 1.0;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    // Input values for Example 14
    double lambda = 8.0;  // Arrival rate
    double mu = 5.0;      // Service rate
    int c = 2;            // Number of servers

    double rho = lambda / (c * mu);  // Traffic intensity
    double sum = 0.0;

    // Part 1: Summation from n = 0 to (c - 1)
    for (int n = 0; n < c; n++)
        sum += pow(lambda / mu, n) / factorial(n);

    // Part 2: Term at n = c
    double lastTerm = pow(lambda / mu, c) / (factorial(c) * (1 - rho));

    double p0 = 1.0 / (sum + lastTerm);  // Probability system is empty

    // Lq (average number of customers in queue)
    double Lq = (p0 * pow(lambda / mu, c) * rho) /
                (factorial(c) * pow(1 - rho, 2));

    // Ls (in system) = Lq + λ / μ
    double Ls = Lq + (lambda / mu);

    // Ws = Ls / λ
    double Ws = Ls / lambda;

    // Wq = Lq / λ
    double Wq = Lq / lambda;

    // Output results
    printf("M/M/%d Queue Results:\n", c);
    printf("Lq (avg. in queue): %.4f\n", Lq);
    printf("Ls (avg. in system): %.4f\n", Ls);
    printf("Wq (waiting time): %.4f\n", Wq);
    printf("Ws (system time): %.4f\n", Ws);

    return 0;
}
