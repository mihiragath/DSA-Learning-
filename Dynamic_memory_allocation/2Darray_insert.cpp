#include <iostream>
using namespace std;

int main() {

    // Input the number of rows for the 2D array
    int row;
    cin >> row;

    // Input the number of columns for the 2D array
    int col;
    cin >> col;

    // Creating a 2D array dynamically using pointers
    // 'arr' is a pointer to an array of pointers (int*)
    int** arr = new int*[row];
    // For each row, allocate memory for columns
    for(int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    // Taking input for the 2D array
    cout << "Enter array elements:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> arr[i][j];  // Input each element
        }
    }

    // Output the 2D array elements
    cout << "Array elements are:" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";  // Print each element
        }
        cout << endl;  // Move to next row after printing one row
    }

    // Releasing dynamically allocated memory
    for(int i = 0; i < row; i++) {
        delete [] arr[i];  // Free memory allocated for each row
    }

    delete [] arr;  // Free memory allocated for the array of pointers (the rows)

    // The program dynamically creates a 2D array, handles input/output, and frees memory correctly
    return 0;
}
