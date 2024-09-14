#include <iostream>

using namespace std;

// Function to perform binary search
// It returns the index of the element 'key' in the array 'arr' if found, otherwise -1
int binarySearch(int arr[], int size, int key) {
    int start = 0;               // Initial starting index
    int end = size - 1;           // Initial ending index
    
    // Calculate the middle index
    int mid = start + (end - start) / 2;

    // Loop until the start index is less than or equal to the end index
    while (start <= end) {
        // If the key is found at the mid position, return its index
        if (arr[mid] == key) {
            return mid;
        }

        // If the key is greater than the mid element, search the right half
        if (key > arr[mid]) {
            start = mid + 1; // Move the start to mid + 1
        } 
        // If the key is smaller than the mid element, search the left half
        else {
            end = mid - 1; // Move the end to mid - 1
        }

        // Recalculate the mid position after adjusting start and end
        mid = start +(end - start) / 2;
    }

    // If the key is not found, return -1
    return -1;
}

int main() {
    // Array of even length
    int even[6] = {1, 2, 3, 4, 5, 6};

    // Array of odd length
    int odd[5] = {1, 2, 3, 4, 5};

    // Call the binarySearch function for the 'even' array, searching for the value 4
    int index = binarySearch(even, 6, 4);

    // Print the result
    cout << "Index of 4 is: " << index << endl;

    return 0;
}
