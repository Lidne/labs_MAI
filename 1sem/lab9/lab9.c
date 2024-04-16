#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

unsigned int STEPS = 50;

int abs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int sign(int x) {
    if (x < 0) {
        return -1;
    } else {
        return 1;
    }
}

int max1(int x, int y) {
    return (x > y ? x : y);
}

int min1(int x, int y) {
    return (x < y ? x : y);
}

bool isInArea(int x, int y) {
    return (((((x + 10) * (x + 10)) + ((y + 10) * (y + 10))) <= 100) && ((((x + 20) * (x + 20)) + ((y + 20) * (y + 20))) <= 100));
}

int main() {
    int i = 5, j = 5, l = 4, step = 0;
    int tmpI, tmpJ;
    while (step <= STEPS) {
        tmpI = i;
        tmpJ = j;
        ++step;
        printf("i: %d, j: %d, k: %d\n", i, j, step);
        if (isInArea(i, j)) {
            printf("Reaching destination area on step %d.", step);
            printf("i: %d, j: %d, k: %d\n", i, j, step);
            return 0;
        }
        i = (i / 3) - (abs(i - step) * sign(l - j));
        j = (j % 10) - (max1(tmpI, l) % (step + 1));
        l = tmpI + ((tmpJ * step) % 5) + (l / 5) + 3;
    }
    printf("Miss\nStep: %d, i: %d, j: %d, l: %d", step, i, j, l);
    return 0;
}