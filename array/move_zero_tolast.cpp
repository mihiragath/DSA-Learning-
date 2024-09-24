#include <iostream> 

using namespace std;

// Function to move all zeros to the end of the array
void moveLast(int arr[], int n) {
    int i = 0; // Pointer to track non-zero elements

    // Traverse through the array
    for (int j = 0; j < n; j++) {
        // If the current element is not zero, we swap it with the element at index i
        if (arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++; // Move the pointer to the next position for non-zero elements
        }
    }
    // After the loop, all non-zero elements are at the beginning, and all zeros are at the end.
}

int main() {
    int arr[] = {1, 0, 6, 0, 9, 0, 0}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    moveLast(arr, n); // Call the function to move zeros to the end

    // Output the modified array
    cout << "Array after moving zeros to the end: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
