#include <stdio.h>

int main() {
    FILE *in = fopen("in.txt", "r");
    int val;
    while (fscanf(in, "%d", &val) != EOF) {
        printf("%d\n", val);
    }
    return 0;
}