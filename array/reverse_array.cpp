#include <iostream>

using namespace std;

// Function to reverse the elements of the array
void reverseArray(int arr[], int size) {
    int start = 0; // Initialize start index
    int end = size - 1; // Initialize end index

    // Swap elements from start to end until the middle of the array
    while (start < end) {
        // Swap the elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move the indices towards the middle
        start++;
        end--;
    }
}

// Function to print the elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl; // Print a newline after printing the array
}

int main() {
    // Initialize the array
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10; // Size of the array

    // Print the original array
    cout << "Original array: ";
    printArray(arr, size);

    // Reverse the array
    reverseArray(arr, size);

    // Print the reversed array
    cout << "Reversed array: ";
    printArray(arr, size);

    return 0;
}
