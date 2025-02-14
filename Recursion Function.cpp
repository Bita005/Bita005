#include <iostream>
using namespace std;

void selectionSortRecursive(int arr[], int n, int index = 0) {
    if (index >= n - 1) {
        return;
    }

    int minIndex = index;
    for (int j = index + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }

    swap(arr[index], arr[minIndex]);
    selectionSortRecursive(arr, n, index + 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    printArray(arr, n);

    selectionSortRecursive(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}
