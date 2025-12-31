#include <stdio.h>

int partition(int A[], int left, int right) {
    int L = left;
    int pivot = A[L],temp;
    
    while (left < right) {
        while (A[left] <= pivot)
        {
            left++;
        }
        while (A[right] > pivot)
            right--;

        if (left < right) {
            temp = A[left];
             A[left] =  A[right];
            A[right]= temp;
        }
    }
A[L]=A[right];
A[right]=pivot;

    return right;
}

void quickSort(int A[], int L, int R) {
    int p;
    if (L < R) {
        p = partition(A,L,R);
        quickSort(A,L,p- 1);
        quickSort(A,p+1,R);
    }
}

int main() {
  int A[]={56,3,9,1,33,5,4,81,70};
  int i,n=9;
  
    quickSort(A, 0, 8);

    printf("Quick Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}