#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[15], choice, key, pos;

    printf("Enter 15 numbers:\n");
    for (int i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    scanf("%d", &choice);

    if (choice == 1) {
        bubbleSort(arr, 15);
        printf("\nArray sorted using Bubble Sort.\n");
    } else {
        insertionSort(arr, 15);
        printf("\nArray sorted using Insertion Sort.\n");
    }

    printf("Sorted array: ");
    for (int i = 0; i < 15; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter key to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, 15, key);
    if (pos != -1)
        printf("Key %d found at position %d (0-based index).\n", key, pos);
    else
        printf("Key %d not found in the array.\n", key);

    return 0;
}