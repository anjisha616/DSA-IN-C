#include <stdio.h>

int main() {
    int A[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = 8;
    int gap, i, j, temp;

    // Shell Sort logic
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        for (i = gap; i < n; i++) {
            temp = A[i];
            j = i-gap;

            while (j >= 0 && A[j] > temp) {
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }

    printf("Shell sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}