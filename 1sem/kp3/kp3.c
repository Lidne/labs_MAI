#include <stdio.h>
#include <math.h>

const double a = 0.0;
const double b = 0.5;
const double k = 1.0;
const int n = 100;
const int fieldSize = 18;
const int columnsCount = 4;

double calcEps() { // функция для рассчета машинного эпсилон
    double eps = 1.0;
    while (1.0 + eps > 1.0) eps /= 2.0;
    return eps * 2.0;
}

double pow_(double x, int n) { // функция возведения в степень
    double res = 1.0;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}

double factorial(int n) {
    double res = 1.0;
    while (n) {
        res *= (double) n;
        --n;
    }
    return res;
}

double calcFunction(double x) { // вычисление значения функции
    return (1 - (x * x / 2.0)) * cos(x) - (x / 2.0) * sin(x);
}

double calcTaylor(double x, double eps, int *iterationsCount) { // вычисление значения ряда тейлора
    double res = 0.0;
    double prev = 0.0; // прошлое значение
    int n = 0;
    
    do {
        prev = res;
        res += pow_(-1.0, n) * (2 * n * n + 1) * pow_(x, 2 * n) / factorial(2 * n);
        n++;
    } while (fabs(res - prev) >= k * eps); // условие сходимости

    *iterationsCount = n;

    return res;
}

double printSplitter() { // функция для вывода разделителя таблицы
    int columnWidth = fieldSize + 3;

    for (int i = 0; i < columnWidth * columnsCount; i++) {
        if (i % columnWidth == 0) {
            printf("+");
            continue;
        } 

        printf("-");
    }

    printf("+\n");
    return 0;
}

int printHeader() { // функция для вывода заголовка
    printf("| %18s | %18s | %18s | %18s |\n", "x value", "f(x) - built-in", "f(x) - Taylor", "Iterations");
    return 0;
}

int main() {
    double step = (b - a) / n;
    double x = a;
    double eps = calcEps();
    int iterationsMax = 0;

    printSplitter();
    printHeader();
    printSplitter();

    for (int i = 0; i < n + 1; i++) {
        double fVal = calcFunction(x);
        
        int iterationsCount;
        double fTaylorVal = calcTaylor(x, eps, &iterationsCount);
        if (iterationsCount > iterationsMax) iterationsMax = iterationsCount;

        printf("| %18.15f | %18.15f | %18.15f | %18d |\n", x, fVal, fTaylorVal, iterationsCount);
        x += step;
    }

    printSplitter();
    printf("Max iterations count was: %d", iterationsMax);

    return 0;
}

// int main() {
//     printf("%f", factorial(5));
// }