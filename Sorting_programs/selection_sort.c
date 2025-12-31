#include <stdio.h>

int main() {
    int  n=8, i, j, minindex, temp;
int A[]={44,22,12,11,7,9,19};
    // Selection Sort logic
    for (i = 0; i < n - 1; i++) {
        minindex = i;

        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minindex]) {
                minindex = j;
            }
        }

        // Swap
        if (minindex != i) {
            temp = A[i];
            A[i] = A[minindex];
            A[minindex] = temp;
        }
    }

    printf("Selection Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
