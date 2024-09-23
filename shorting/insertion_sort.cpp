#include <iostream>

using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    // Loop through the array starting from the second element
    for(int i = 1; i < n; i++) {
        int temp = arr[i];  // Store the current element in temp
        int j = i - 1;

        // Shift elements of the sorted part of the array to the right
        // until we find the correct position for temp
        for(; j >= 0; j--) {
            if(arr[j] > temp) {  // If the current element is larger than temp
                arr[j + 1] = arr[j];  // Shift the element to the right
            } else {
                break;  // Break the loop if the correct position for temp is found
            }
        }

        // Insert the temp element in its correct position
        arr[j + 1] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Print each element of the array
    }
    cout << endl;  // Move to the next line after printing
}

int main() {
    int arr[] = {2, 1, 4, 5, 7};  // Initialize the array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, size);  // Print the original unsorted array

    insertionSort(arr, size);  // Call the insertion sort function to sort the array

    cout << "Sorted array: ";
    printArray(arr, size);  // Print the sorted array

    return 0;  // Exit the program
}
