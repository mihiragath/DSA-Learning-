#include <iostream> 

using namespace std;

// Function to find the first occurrence of 'key' in array 'arr'
int firstOcc(int arr[], int size, int key) {
    int start = 0;               // Initial starting index
    int end = size - 1;           // Initial ending index
    int ans = -1;                 // To store the answer (index of first occurrence)

    // Loop until the start index is less than or equal to the end index
    while (start <= end) {
        // Calculate the middle index
        int mid = start + (end - start) / 2;

        // If the key is found at the mid position
        if (arr[mid] == key) {
            ans = mid;           // Store the index
            end = mid - 1;       // Move left to find the first occurrence
        }
        // If the key is greater than the mid element, search the right half
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        // If the key is smaller than the mid element, search the left half
        else {
            end = mid - 1;
        }
    }

    // Return the first occurrence index or -1 if not found
    return ans;
}

// Function to find the last occurrence of 'key' in array 'arr'
int lastOcc(int arr[], int size, int key) {
    int start = 0;               // Initial starting index
    int end = size - 1;           // Initial ending index
    int ans = -1;                 // To store the answer (index of last occurrence)

    // Loop until the start index is less than or equal to the end index
    while (start <= end) {
        // Calculate the middle index
        int mid = start + (end - start) / 2;

        // If the key is found at the mid position
        if (arr[mid] == key) {
            ans = mid;           // Store the index
            start = mid + 1;     // Move right to find the last occurrence
        }
        // If the key is greater than the mid element, search the right half
        else if (key > arr[mid]) {
            start = mid + 1;
        } 
        // If the key is smaller than the mid element, search the left half
        else {
            end = mid - 1;
        }
    }

    // Return the last occurrence index or -1 if not found
    return ans;
}

int main() {
    // Array of even length
    int even[6] = {1, 2, 4, 4, 4, 6};

    // Test first occurrence
    cout << "First occurrence of 4 is at index: " << firstOcc(even, 6 , 4) << endl;

    // Test last occurrence
    cout << "Last occurrence of 4 is at index: " << lastOcc(even, 6 , 4) << endl;

    return 0;
}
