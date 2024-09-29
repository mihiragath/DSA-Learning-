#include <iostream>
using namespace std;

// Function to search for a target value in a 2D matrix
bool searchMatrix(int matrix[][4], int rows, int cols, int target) {
    int start = 0;                  // Initialize start of the search range
    int end = rows * cols - 1;       // Initialize end of the search range

    // Perform binary search on the entire 2D array as if it were a 1D array
    while (start <= end) {
        int mid = start + (end - start) / 2;  // Calculate the middle index
        
        // Get the middle element from the 2D matrix
        int element = matrix[mid / cols][mid % cols]; // Convert 1D index to 2D
        
        // If the middle element matches the target, return true
        if (element == target) {
            return true;
        }
        
        // If the middle element is smaller than the target, search in the right half
        if (element < target) {
            start = mid + 1;
        } 
        // Otherwise, search in the left half
        else {
            end = mid - 1;
        }
    }
    
    // If the loop ends, the target was not found, return false
    return false;
}

int main() {
    // Example 4x4 matrix
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    // Target to search for
    int target = 16;

    // Call the function and print the result
    if (searchMatrix(matrix, 3, 4, target)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
