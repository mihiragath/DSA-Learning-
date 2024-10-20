#include<iostream>
using namespace std;

void merge(int arr[], int start, int end) {
    int mid = start + (end - start) / 2;

    // Calculate sizes of two subarrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temp arrays
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy data to temp arrays
    for (int i = 0; i < len1; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[]
    int i = 0, j = 0, k = start;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements of left[]
    while (i < len1) {
        arr[k++] = left[i++];
    }

    // Copy remaining elements of right[]
    while (j < len2) {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);       // Sort first half
    mergeSort(arr, mid + 1, end);     // Sort second half
    merge(arr, start, end);           // Merge the two halves
}

int main() {
    int arr[] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
