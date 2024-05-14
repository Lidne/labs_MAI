#include <iostream>

#include "stack.h"

void swap(int arr[], int index1, int index2) {
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void selectionSort(Stack &s) {
    for (int i = 0; i < s.length - 1; ++i) {
        int min_i = i;
        for (int j = i + 1; j < s.length; ++j) {
            if (s.data[j] < s.data[min_i]) {
                min_i = j;
            }
        }
        if (min_i != i) {
            swap(s.data, i, min_i);
        }
    }
}

int findMin(Stack &s) {
    Stack s1 = newStack(s.length);
    Stack s2 = newStack(s.length);

    int m = -1;
    for (int i = 0; i < s.length; ++i) {
        int tmp = pullStack(s);
        m = m > tmp ? m : tmp;
        pushStack(s1, tmp);
    }

    for (int i = 0; i < s.length; ++i) {
        int tmp = pullStack(s1);
        if (tmp != m) pushStack(s2, tmp);
    }
    newStack(s, s.length);
    copyStack(s, s2);
    return m;
}

int main() {
    Stack s = newStack(10);
    // for (int i = 0; i < 10; ++i) {
    //     pushStack(s, i);
    // }
    pushStack(s, 2);
    pushStack(s, 1);
    pushStack(s, 0);
    pushStack(s, 12);
    pushStack(s, 1);
    pushStack(s, 6);
    pushStack(s, 5);
    pushStack(s, 9);
    pushStack(s, -1);
    pushStack(s, 3);
    // cout << findMin(s) << endl;
    printStack(s);
    int msd = findMin(s);
    cout << msd << endl;
    printStack(s);
    selectionSort(s);
    printStack(s);
}