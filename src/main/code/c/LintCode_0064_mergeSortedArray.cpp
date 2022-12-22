#include <iostream>
#include <vector>
using namespace std;

// https://www.lintcode.com/problem/64
void mergeSortedArray(int A[], int m, int B[], int n) {
    if (A == NULL || B == NULL) {
        return;
    }

    int index = m + n - 1;
    int aIndex = m - 1;
    int bIndex = n - 1;

    while (aIndex >= 0 && bIndex >= 0) {
        if (A[aIndex] >= B[bIndex]) {
            A[index--] = A[aIndex--];
        } else {
            A[index--] = B[bIndex--];
        }
    }

    while (aIndex >= 0) {
        A[index--] = A[aIndex--];
    }

    while (bIndex >= 0) {
        A[index--] = B[bIndex--];
    }
}