#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void Merge(int arr[], int low, int mid, int high) {
    int* b = (int*)malloc((MAX_SIZE + 1) * sizeof(int));
    int i, j, k;
    for (k = 0; k <= high; k++) {
        b[k] = arr[k];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (b[i] <= b[j]) {
            arr[k] = b[i++];
        }
        else {
            arr[k] = b[j++];
        }
    }
    while (i <= mid) {
        arr[k++] = b[i++];
    }
    while (j <= high) {
        arr[k++] = b[j++];
    }
}

void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int arr[MAX_SIZE] = { 3, 1, 5, 2, 4 };
    printf("排序前：");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    MergeSort(arr, 0, MAX_SIZE - 1);  // 排序
    printf("\n排序后：");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
