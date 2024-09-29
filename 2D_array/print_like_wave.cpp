#include <iostream>
using namespace std;

// Function to print 2D array in wave pattern
void printWave(int arr[3][3], int rows, int cols) {
    // Traverse through each column
    for (int col = 0; col < cols; col++) {
        // Check if column index is odd (wave pattern)
        if (col % 2 == 1) {
            // Print column from bottom to top
            for (int row = rows - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        } else {
            // Print column from top to bottom
            for (int row = 0; row < rows; row++) {
                cout << arr[row][col] << " ";
            }
        }
    }
    cout << endl; // Newline after printing the wave pattern
}

int main() {
    // Initialize a 3x3 array
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print wave pattern for the 3x3 array
    cout << "Wave print of the array:" << endl;
    printWave(arr, 3, 3); // Pass array, rows, and columns

    return 0;
}
