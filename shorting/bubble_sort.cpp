#include <iostream>

using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped=false;
    // Outer loop to traverse through all array elements
    for (int i = 1; i < n ; i++) {  // Run n-1 times for sorting

        // Inner loop for comparison and swapping
        for (int j = 0; j < n - i ; j++) {  // Loop through the unsorted part
            if (arr[j] > arr[j+1]) {  // Compare adjacent elements
                swap(arr[j], arr[j+1]);  // Swap if the current element is greater than the next
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
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

    bubbleSort(arr, size);  // Call the bubble sort function to sort the array

    cout << "Sorted array: ";
    printArray(arr, size);  // Print the sorted array

    return 0;  // Exit the program
}
