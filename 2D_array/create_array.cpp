#include <iostream>
using namespace std;

// Function to check if the element is present and return its index
bool isPresent(int arr[3][3], int n, int& row, int& col) {
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (arr[row][col] == n) {
                return true; // Element found
            }
        }
    }
    return false; // Element not found
}

int main() {
    int arr[3][3];

    // Taking row-wise input
    cout << "Enter elements row-wise:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element for position (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }

    // Printing the array row-wise
    cout << "Array printed row-wise:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Printing the array column-wise
    cout << "Array printed column-wise:" << endl;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Search for an element in the array
    int n;
    cout << "Enter element to search: ";
    cin >> n;

    int row , col; // Variables to store the index of the element if found

    if (isPresent(arr, n, row, col)) {
        cout << "Element " << n << " is present at index (" << row << ", " << col << ")." << endl;
    } else {
        cout << "Element " << n << " is not present in the array." << endl;
    }

    return 0;
}
