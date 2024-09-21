#include <iostream>

using namespace std;

// Function to find the pivot element (smallest element) in the rotated sorted array
int getPivot(int arr[], int n) {
    int s = 0;                   // Starting index
    int e = n - 1;               // Ending index
    int mid = s + (e - s) / 2;    // Calculate middle index

    // Loop until start and end converge
    while (s < e) {
        // If the middle element is greater than or equal to the first element,
        // this means the smallest element lies in the right half
        if (arr[mid] >= arr[0]) {
            s = mid + 1;          // Move start to mid + 1
        }
        // Otherwise, the smallest element is in the left half
        else {
            e = mid;              // Move end to mid
        }
        mid = s + (e - s) / 2;     // Recalculate middle index
    }
    return s;                     // s will hold the index of the smallest element (pivot)
}

// Standard binary search function to find the key in the array
int binarySearch(int arr[], int start, int end, int key) {
    int mid = start + (end - start) / 2;  // Calculate the middle index

    // Loop until the search space is exhausted
    while (start <= end) {
        if (arr[mid] == key) {     // If the key is found
            return mid;
        }
        if (key > arr[mid]) {      // If the key is greater than mid element, search in the right half
            start = mid + 1;
        } 
        else {                     // Otherwise, search in the left half
            end = mid - 1;
        }
        mid = start + (end - start) / 2;  // Recalculate middle index
    }
    return -1;                     // Key not found
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3};  // Rotated sorted array
    int n = 5;                     // Size of the array
    int k = 2;                     // Element to be searched

    // Find the pivot (smallest element's index)
    int pivot = getPivot(arr, n);

    // Check which part of the array contains the element to be searched
    int result;
    if (k >= arr[pivot] && k <= arr[n - 1]) {
        // If the key lies in the second half (right side of the pivot)
        result = binarySearch(arr, pivot, n - 1, k);
    } else {
        // If the key lies in the first half (left side of the pivot)
        result = binarySearch(arr, 0, pivot - 1, k);
    }

    // Print the result
    if (result != -1) {
        cout << "Element " << k << " found at index: " << result << endl;
    } else {
        cout << "Element " << k << " not found in the array." << endl;
    }

    return 0;
}
