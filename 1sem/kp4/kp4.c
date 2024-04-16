#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return exp(x) + sqrt(1.0 + exp(2.0 * x)) - 2;
}

double dihotomia(double a, double b, double eps) {
    while(fabs(a - b) >= eps) {
        if ((f(a) * f((a + b) / 2.0)) > 0) {
            a = (a + b) / 2.0;
        }
        if ((f(b) * f((a + b) / 2.0)) > 0) {
            b = (a + b) / 2.0;
        }
    }
    return (a + b) / 2.0;
}

int main() {
    double reference = -0.2877;
    double a = -1.0;
    double b = 0.0;
    double eps = 0.0001;

    double solution = dihotomia(a, b, eps);
    double fVal = f(solution);

    printf("Reference root: %f\nDihotomia method: %f\nF(x) = %e", reference, solution, fVal);

    return 0;
}