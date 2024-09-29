#include <iostream>
using namespace std;

// Function to compute the sum of each row and find the row with the maximum sum
int rowWise(int arr[3][3]) {
    int maxSum = 0; // Variable to keep track of the maximum sum
    int maxRowIndex = -1; // Variable to store the index of the row with the maximum sum
    
    cout << "Sum of all rows is: " << endl;
    for (int row = 0; row < 3; row++) {
        int sum = 0; // Initialize sum for each row
        for (int col = 0; col < 3; col++) {
            sum += arr[row][col]; // Add elements of the row
        }
        cout << "Row " << row << ": " << sum << endl;
        
        // Update the maxSum and maxRowIndex if the current row sum is greater than maxSum
        if (sum > maxSum) {
            maxSum = sum;
            maxRowIndex = row;
        }
    }
    cout << "Row with maximum sum is Row " << maxRowIndex << " with sum " << maxSum << endl;
    return maxRowIndex; // Return the row index with maximum sum
}

// Function to compute the sum of each column and find the column with the maximum sum
int colWise(int arr[3][3]) {
    int maxSum = 0; // Variable to keep track of the maximum sum
    int maxColIndex = -1; // Variable to store the index of the column with the maximum sum

    cout << "Sum of all columns is: " << endl;
    for (int col = 0; col < 3; col++) {
        int sum = 0; // Initialize sum for each column
        for (int row = 0; row < 3; row++) {
            sum += arr[row][col]; // Add elements of the column
        }
        cout << "Column " << col << ": " << sum << endl;

        // Update the maxSum and maxColIndex if the current column sum is greater than maxSum
        if (sum > maxSum) {
            maxSum = sum;
            maxColIndex = col;
        }
    }
    cout << "Column with maximum sum is Column " << maxColIndex << " with sum " << maxSum << endl;
    return maxColIndex; // Return the column index with maximum sum
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

    cout << "----------" << endl;
    
    // Call the function to find the row with maximum sum
    rowWise(arr);

    cout << "----------" << endl;
    
    // Call the function to find the column with maximum sum
    colWise(arr);

    return 0;
}
