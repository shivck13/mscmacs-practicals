#include <stdio.h>
#include <math.h>

int main() {
    int n = 3;
    printf("Enter number of observations: ");
    scanf("%d", &n);

    double x[n], sum = 0.0, mu, sigma2 = 0.0;

    printf("Enter %d data values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
        sum += x[i];
    }

    // Maximum Likelihood Estimator for mean
    mu = sum / n;

    // MLE for variance
    for (int i = 0; i < n; i++) {
        sigma2 += (x[i] - mu) * (x[i] - mu);
    }
    sigma2 /= n;

    printf("\nMLE of Mean (mu): %.4f\n", mu);
    printf("MLE of Variance (sigma^2): %.4f\n", sigma2);

    return 0;
}
