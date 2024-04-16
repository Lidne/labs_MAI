int main() {
    double a = 0;
    double b = 0.5;
    double h = (b - a) / 10;
    double eps = 1;
    while (1.0 + eps > 1.0) {
        eps /= 2;
    }
    eps *= 2;
    for (double x = 0; fabs(x - b) < eps; x += h) {
        int n = 1;
        double S = 3 * x;
        double p = x;
        double k = 1;
        while (fabs(k*p) < eps) {
            ++n;
            k = n * (n + 2);
            p *= x;
            
        }
    }
}