#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j + 1] < arr[j]) swap(arr[j], arr[j + 1]);
        }
    }
}

// начало сортировки вставками (для внешней памяти)
void merge(int *a, int l1, int r1, int *b, int l2, int r2, int *c, int s) {
    // сортировка слиянием
    int i = l1, j = l2, k = s;
    while ((i <= r1) && (j <= r2)) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    for (; i <= r1; i++) {
        c[k] = a[i];
        k++;
    }

    for (; j <= r2; j++) {
        c[k] = b[j];
        k++;
    }
}


void move(int *a, int l, int r, int *b, int s) {
    int k = s;
    for (int i = l; i <= r; i++) {
        b[k] = a[i];
        k++;
    }
}

void sorts(int *a, int l, int r, int *b) {
    if (l >= r) return;
    int m = (l + r) / 2;
    sorts(a, l, m, b);
    sorts(a, m + 1, r, b);
    merge(a, l, m, a, m + 1, r, b, l);
    move(b, l, r, a, l);
}
// конец сортировки слиянием

void sort(int *a, int n) {
    int *b = new int[n];
    sorts(a, 0, n - 1, b);
    delete[] b;
}

void quickSort() {
}

//
void F1(int a) { cout << "a: " << a << endl; }
void F2(int b) { cout << "b: " << b << endl; }

int main() {
    int n = 10;
    int arr[] = {2, 5, 1, 8, 3, 4, 0, 7, 6, 9};

    bubbleSort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int *pti = NULL;
    void (*ptF)(int) = &F1;
    ptF = F1;
    ptF(4);
}
