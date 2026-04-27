#include <stdio.h>
#include <stdbool.h>

// void BubbleSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         bool flag = false;
//         for (int j = n - 1; j > i; j--) {
//             if (arr[j - 1] > arr[j]) {
//                 int temp = arr[j - 1];
//                 arr[j - 1] = arr[j];
//                 arr[j] = temp;
//                 flag = true;
//             }
//         }
//         if (flag == false) {
//             return;
//         }
//     }
// }

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if (flag == false) {
            return;
        }
    }
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(arr, low, high);
        QuickSort(arr, low, pivotpos - 1);
        QuickSort(arr, pivotpos + 1, high);
    }
}

int main() {
    int a[] = { 5, 2, 4, 1, 3 };
    int length = sizeof(a) / sizeof(a[0]);
    // BubbleSort(a, length);
    QuickSort(a, 0, length - 1);
    for (int k = 0; k < length; k++) {
        printf("%d ", a[k]);
    }
    return 0;
}