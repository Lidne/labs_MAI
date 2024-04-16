#include <stdio.h>
#include <stdlib.h>

// функиця считывает матрицу из файла и возвращает ее
int readMatrix(int* arr, const char *filename) {
    FILE *in = fopen(filename, "r");
    if (in == NULL) {
        printf("File not found\n");
        return 0;
    }
    int val, i = 0;

    while (fscanf(in, "%d", &val) != EOF) {
        arr[i] = val;
        ++i;
    }
    fclose(in);
    return i;
}

// фукнция высчитывает порядок матрицы
// т.к. размеры матриц варъируются от 1 до 8, то сложность алгоритма некритична
int findMatrixSize(int len) { 
    for (int i = 1; i < len; ++i) {
        if ((i * i) == len) {
            return i;
        }
    }
    return 0;
}

// фукнция для создания двумерной матрицы
int** createMatrix(int n) {
    int** array = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        array[i] = (int*)malloc(n * sizeof(int));
    }
    return array;
}

// функция разворачивает матрицу в одномерный массив
// против часовой (CCW - Counter Clockwise)
int makeSpiralCCW(int* arr, int len) { 

    int n = findMatrixSize(len), i, j;
    int** matrix2D = createMatrix(n);
    for (i = 0; i < len; ++i) {
        matrix2D[i / n][i % n] = arr[i];
    }

    int top = 0, bot = n - 1, left = 0, right = n - 1, count = 0;
    
    while (1) {
        if (top > bot) break;

        // левый столбец
        for (i = top; i <= bot; ++i) {
            arr[count] = matrix2D[i][left];
            ++count;
        }
        ++left;
        if (left > right) break;

        // нижняя строка
        for (j = left; j <= right; ++j) {
            arr[count] = matrix2D[bot][j];
            ++count;
        }
        --bot;
        if (top > bot) break;

        // правый столбец
        for (i = bot; i >= top; --i) {
            arr[count] = matrix2D[i][right];
            ++count;
        }
        --right;
        if (left > right) break;

        // верхняя строка
        for (j = right; j >= left; --j) {
            arr[count] = matrix2D[top][j];
            ++count;
        }
        ++top;
    }
    return 0;
}

// функция разворачивает матрицу в одномерный массив
// по часовой (CW - Clockwise)
int makeSpiralCW(int* arr, int len) { 

    int n = findMatrixSize(len), i, j;
    int** matrix2D = createMatrix(n);
    for (i = 0; i < len; ++i) {
        matrix2D[i / n][i % n] = arr[i];
    }

    int top = 0, bot = n - 1, left = 0, right = n - 1, count = 0;
    
    while (1) {
        if (left > right) break;

        // верхняя строка
        for (j = left; j <= right; ++j) {
            arr[count] = matrix2D[top][j];
            ++count;
        }
        ++top;
        if (top > bot) break;

        // правый столбец
        for (i = top; i <= bot; ++i) {
            arr[count] = matrix2D[i][right];
            ++count;
        }
        --right;
        if (left > right) break;

        // нижняя строка
        for (j = right; j >= left; --j) {
            arr[count] = matrix2D[bot][j];
            ++count;
        }
        --bot;
        if (top > bot) break;

        // левый столбец
        for (i = bot; i >= top; --i) {
            arr[count] = matrix2D[i][left];
            ++count;
        }
        ++left;
    }
    return 0;
}

// функция сдвигает одномерный массив на n элементов вперед
int shiftArr(int* arr, int len, int n) {
    int tmpArr[len];
    // int prev = arr[0], tmp;
    for (int i = 0; i < len; ++i) {
        tmpArr[(i + n) % len] = arr[i];
    }

    for (int i = 0; i < len; ++i) {
        arr[i] = tmpArr[i];
    }
    return 0;
}

// функция сворачивает одномерный массив в матрицу
// против часовой (CCW - Counter Clockwise)
int** make2DCCW(int* arr, int len) { 

    int n = findMatrixSize(len), i, j;
    int** matrix2D = createMatrix(n);

    int top = 0, bot = n - 1, left = 0, right = n - 1, count = 0;
    
    while (1) {
        if (top > bot) break;

        // левый столбец
        for (i = top; i <= bot; ++i) {
            matrix2D[i][left] = arr[count];
            ++count;
        }
        ++left;
        if (left > right) break;

        // нижняя строка
        for (j = left; j <= right; ++j) {
            matrix2D[bot][j] = arr[count];
            ++count;
        }
        --bot;
        if (top > bot) break;

        // правый столбец
        for (i = bot; i >= top; --i) {
            matrix2D[i][right] = arr[count];
            ++count;
        }
        --right;
        if (left > right) break;

        // верхняя строка
        for (j = right; j >= left; --j) {
            matrix2D[top][j] = arr[count];
            ++count;
        }
        ++top;
    }
    return matrix2D;
}

// функция сворачивает одномерный массив в матрицу
// по часовой (CW - Clockwise)
int** make2DCW(int* arr, int len) { 

    int n = findMatrixSize(len), i, j;
    int** matrix2D = createMatrix(n);

    int top = 0, bot = n - 1, left = 0, right = n - 1, count = 0;
    
    while (1) {
        if (left > right) break;

        // верхняя строка
        for (j = left; j <= right; ++j) {
            matrix2D[top][j] = arr[count];
            ++count;
        }
        ++top;
        if (top > bot) break;

        // правый столбец
        for (i = top; i <= bot; ++i) {
            matrix2D[i][right] = arr[count];
            ++count;
        }
        --right;
        if (left > right) break;

        // нижняя строка
        for (j = right; j >= left; --j) {
            matrix2D[bot][j] = arr[count];
            ++count;
        }
        --bot;
        if (top > bot) break;

        // левый столбец
        for (i = bot; i >= top; --i) {
            matrix2D[i][left] = arr[count];
            ++count;
        }
        ++left;
    }
    return matrix2D;
}


int printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int main() {
    int arr[100];
    char filename[256];
    scanf("%s", filename); // считываем название файла
    int len = readMatrix(arr, filename); // считывание матрицы из файла
    int n = findMatrixSize(len); // рассчет порядка матрицы
    int N = 1; // шаг сдвига

    makeSpiralCCW(arr, len); // разворачиваем элементы
    shiftArr(arr, len, N); // сдвигаем на N

    int** matrix = make2DCCW(arr, len); // обратно сворачиваем

    // вывод матрицы
    printMatrix(matrix, n);
}