#include <stdio.h>
#include <math.h>



int main() {
    
    long double n, ost;
    int t;
    scanf("%Lf %d", &n, &t);
    printf("%x.", (unsigned int) n);
    
    
    for (int i = 0; i < t; i ++) {
        n -= trunc(n);
        n *= 16;
        if (trunc(n) == 15) {
            printf("F");
        }
        if (trunc(n) == 14) {
            printf("E");
        }
        if (trunc(n) == 13) {
            printf("D");
        }
        if (trunc(n) == 12) {
            printf("C");
        }
        if (trunc(n) == 11) {
            printf("B");
        }
        if (trunc(n) == 10) {
            printf("A");
        }
        if (trunc(n) < 10 ) {
            printf("%d", (int) trunc(n));
        }
    }
}