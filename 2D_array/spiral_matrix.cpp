#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Function to print matrix elements in spiral order
void spiralOrder(int matrix[ROWS][COLS], int rows, int cols) {
    // Define the boundaries of the matrix
    int top = 0, bottom = rows - 1;  // Top and bottom boundaries
    int left = 0, right = cols - 1;  // Left and right boundaries
    
    // Continue the process while the boundaries are valid
    while (top <= bottom && left <= right) {
        // Traverse from left to right on the top row
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";  // Print top row from left to right
        }
        top++;  // Move the top boundary down to the next row

        // Traverse from top to bottom on the right column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";  // Print right column from top to bottom
        }
        right--;  // Move the right boundary left to the previous column

        // Traverse from right to left on the bottom row, if there is a row to process
        if (top <= bottom) {  // Ensure there is still a row to process
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";  // Print bottom row from right to left
            }
            bottom--;  // Move the bottom boundary up to the previous row
        }

        // Traverse from bottom to top on the left column, if there is a column to process
        if (left <= right) {  // Ensure there is still a column to process
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";  // Print left column from bottom to top
            }
            left++;  // Move the left boundary right to the next column
        }
    }
}

int main() {
    // Initialize a 3x3 matrix
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function to print the matrix elements in spiral order
    cout << "Spiral order of the matrix: ";
    spiralOrder(matrix, ROWS, COLS);  // Pass the matrix and its dimensions to the function

    return 0;
}
