#include <iostream>

using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    // Loop to iterate over the array
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume the current element is the minimum

        // Loop to find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {  // Compare current element with assumed minimum
                minIndex = j;  // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        swap(arr[minIndex], arr[i]);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};  // Initialize the array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, size);  // Print the original array

    selectionSort(arr, size);  // Call the selection sort function

    cout << "Sorted array: ";
    printArray(arr, size);  // Print the sorted array

    return 0;
}
