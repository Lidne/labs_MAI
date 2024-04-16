#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

unsigned int STEPS = 50;

int abs(int x) {
    return (x < 0 ? -x : x);
}

int sign(int x) {
    return (x < 0 ? -1 : 1);
}

int max(int x, int y) {
    return (x > y ? x : y);
}

int min(int x, int y) {
    return (x < y ? x : y);
}

bool toleratesCircleEquasion(int x, int y, int x0, int y0, int r) {
    return (((x - x0) * (x - x0)) + ((y - y0) * (y - y0))) <= (r * r);
}

bool isInArea(int x, int y) {
    return toleratesCircleEquasion(x, y, -10, -10, 10) && toleratesCircleEquasion(x, y, -20, -20, 10);
}

int mod(int x, int y) {
    return x - floor((float) x / (float) y) * y;
}

int main() {
    int i = 5, j = 5, l = 4, step = 0;
    int tmpI, tmpJ;
    while (step <= STEPS) {
        tmpI = i;
        tmpJ = j;
        ++step;
        // printf("i: %d, j: %d, k: %d\n", i, j, step);
        if (isInArea(i, j)) {
            printf("Reaching destination area on step %d.", step);
            printf("i: %d, j: %d, k: %d\n", i, j, step);
            return 0;
        }
        i = (i / 3) - (abs(i - step) * sign(l - j));
        j = mod(j, 10) - mod(max(tmpI, l), (step + 1));
        l = tmpI + mod((tmpJ * step), 5) + (l / 5) + 3;
    }
    printf("Miss\nStep: %d, i: %d, j: %d, l: %d", step, i, j, l);
    return 0;
}