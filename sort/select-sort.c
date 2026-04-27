#include <stdio.h>

// Function Prototypes
void SelectSort(int arr[], int n);
void HeapAdjust(int arr[], int k, int len);
void BuildMaxHeap(int arr[], int len);
void HeapSort(int arr[], int len);
void printArray(int arr[], int n);

// ==============================
// Selection Sort (0-based index)
// ==============================
void SelectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// ==============================
// Heap Sort (1-based index)
// ==============================

// Maintain max-heap property for subtree rooted at k
void HeapAdjust(int arr[], int k, int len) {
    arr[0] = arr[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && arr[i] < arr[i + 1])
            i++;
        if (arr[0] >= arr[i])
            break;
        arr[k] = arr[i];
        k = i;
    }
    arr[k] = arr[0];
}

// Build a max heap from an unsorted array
void BuildMaxHeap(int arr[], int len) {
    for (int i = len / 2; i >= 1; i--) {
        HeapAdjust(arr, i, len);
    }
}

// Core heap sort algorithm
void HeapSort(int arr[], int len) {
    BuildMaxHeap(arr, len);
    for (int i = len; i > 1; i--) {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        HeapAdjust(arr, 1, i - 1);
    }
}

// Print array elements
void printArray(int arr[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

// ==============================
// Test Driver
// ==============================
int main() {
    // Test Selection Sort
    printf("Selection Sort: ");
    int a1[] = { 5, 2, 4, 1, 3 };
    int len1 = sizeof(a1) / sizeof(a1[0]);
    SelectSort(a1, len1);
    printArray(a1, len1);

    // Test Heap Sort
    printf("Heap Sort:      ");
    int a2[] = { 0, 5, 2, 4, 1, 3 };
    int len2 = sizeof(a2) / sizeof(a2[0]);
    HeapSort(a2, len2 - 1);

    for (int k = 1; k < len2; k++) {
        printf("%d ", a2[k]);
    }
    printf("\n");

    return 0;
}