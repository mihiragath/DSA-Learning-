#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;

    // Count elements less than or equal to pivot
    for(int i = s + 1; i <= e; i++) {
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // Sort elements on either side of the pivot
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if(s >= e) return;  // Base case

    // Partition the array
    int p = partition(arr, s, e);

    // Recursively sort the left and right partitions
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
