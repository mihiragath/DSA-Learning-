#include <iostream>
using namespace std;

// Function to search for the target in a sorted 2D matrix
bool searchMatrix(int matrix[][4], int rows, int cols, int target) {

    // Start from the top-right corner
    int rowIndex = 0;
    int colIndex = cols - 1;

    // Loop until we go out of bounds
    while (rowIndex < rows && colIndex >= 0) {
        // Access the current element in the matrix
        int element = matrix[rowIndex][colIndex];

        // If the element matches the target, return true
        if (element == target) {
            return true;
        }

        // If the element is less than the target, move to the next row
        if (element < target) {
            rowIndex++;
        }
        // If the element is greater than the target, move to the left column
        else {
            colIndex--;
        }
    }

    // If the target is not found, return false
    return false;
}

int main() {
    // Example 4x4 matrix
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;  // The target element to search for

    // Call the search function
    if (searchMatrix(matrix, 3, 4, target)) {
        cout << "Element found in the matrix!" << endl;
    } else {
        cout << "Element not found in the matrix." << endl;
    }

    return 0;
}
