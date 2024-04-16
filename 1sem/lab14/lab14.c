#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 50;

int** createMatrix(int n) {
    int** array = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        array[i] = (int*)malloc(n * sizeof(int));
    }
    return array;
}

int main() {
    int i, j, n, k;
    scanf("%i", &n); // считывание размера матрицы

    // создание двумерной матрицы
    int** matrix2D = createMatrix(n);

    // запись в одномерный массив
    int m[maxn * maxn]; 
    for (k = 0; k < n * n; ++k) {
        scanf("%d", m + k);
    }

    int diagCount = (2 * (n - 2)) + 3; // количество диагональных рядов
    k = 0;
    for (int d = 0; d <= diagCount; ++d) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i + j == d - 1) { // условия нахождение числа на диагонали (вывел сам)
                    if (d % 2 == 0) {  // если диагональ четная, то заполняем сверху вниз
                        matrix2D[i][j] = m[n * n - k - 1];
                    } else { // если диагональ нечетная, то снизу вверх
                        matrix2D[j][i] = m[n * n - k - 1];
                    }
                        ++k; // идем дальше по массиву чисел
                }
            }
        }
    }

    // вывод матрицы
    printf("\nResult:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%2d ", matrix2D[i][j]);            
        }
        putchar('\n');
    }
}