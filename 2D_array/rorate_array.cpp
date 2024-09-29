#include <iostream>
#include <algorithm> // for std::reverse

using namespace std;

// Function to transpose the matrix (swap rows with columns)
void transpose(int matrix[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);  // Swap elements to transpose the matrix
        }
    }
}

// Function to reverse each row to achieve 90-degree clockwise rotation
void reverseRows(int matrix[3][3], int n) {
    for (int i = 0; i < n; i++) {
        // Reverse the row manually by swapping elements from the start and end of the row
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
}

// Function to rotate the matrix by 90 degrees clockwise
void rotateMatrix(int matrix[3][3], int n) {
    transpose(matrix, n);  // Step 1: Transpose the matrix
    reverseRows(matrix, n); // Step 2: Reverse each row
}

// Function to print the matrix
void printMatrix(int matrix[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";  // Print each element of the matrix
        }
        cout << endl;  // Move to the next line after printing one row
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, 3);  // Print the original matrix

    // Rotate the matrix by 90 degrees clockwise
    rotateMatrix(matrix, 3);

    cout << "Rotated Matrix by 90 degrees clockwise:" << endl;
    printMatrix(matrix, 3);  // Print the rotated matrix

    return 0;
}
