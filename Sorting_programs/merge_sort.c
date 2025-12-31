#include <stdio.h>

void merge(int A[], int left, int right) {
    int end=(left+right)/2,mid=end+1,L=left,i;
    int temp[100];
    int posn=left;

    while (left<=end && mid<=right) {
        if (A[left] <= A[mid]) {
            temp[posn] = A[left];
            left++;
        } else {
            temp[posn] = A[mid];
            mid++;
        }
        posn++;
    }

    while (left <= mid) {
        temp[posn] = A[left];
        left++;
        posn++;
    }

    while (mid <= right) {
        temp[posn] = A[mid];
        mid++;
        posn++;
    }

    for (i = L; i <= right; i++) {
        A[i] = temp[i];
    }
}

void mergeSort(int A[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, right);
    }
}

int main() {
    int A[]={5,8,1,3,77,80,12};
    int n=7,i;
    mergeSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
