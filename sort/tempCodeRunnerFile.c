#include <stdio.h>

void SelectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void HeapAdjust(int arr[], int k, int len) {
    arr[0] = arr[k];
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && arr[i] < arr[i + 1]) {
            i++;
        }
        else if (arr[0] >= arr[i]) {
            break;
        }
        else {
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0];
}

void BuildMaxHeap(int arr[], int len) {
    for (int i = len / 2; i >= 1; i--) {
        HeapAdjust(arr, i, len);
    }
}

void HeapSort(int arr[], int len) {
    BuildMaxHeap(arr, len);
    for (int i = len; i > 1; i--) {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        HeapAdjust(arr, 1, i - 1);
    }
}

int main() {
    int a[] = { 0, 5, 2, 4, 1, 3 };
    int length = sizeof(a) / sizeof(a[0]);
    HeapSort(a, length - 1);
    for (int k = 1; k < length; k++) {
        printf("%d ", a[k]);
    }
    return 0;
}
