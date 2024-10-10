#include <iostream> 
using namespace std; 

// Recursive function to calculate the sum of array elements
int sum(int *arr, int size) {
    // Base case 1: If array size is 0, return 0 (no elements to sum)
    if(size == 0) {
        return 0;
    }
    
    // Base case 2: If there's only one element, return that element
    if(size == 1) {
        return arr[0];
    }

    // Recursive call to calculate the sum of the remaining array
    int sumval = sum(arr + 1, size - 1);

    // Add the first element to the sum of the remaining elements
    int number = arr[0] + sumval;
    return number;
}

int main() {
    // Initialize the array
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    // Call the sum function and store the result
    int sumno = sum(arr, size);

    // Print the sum of the array
    cout << "Sum of array is: " << sumno << endl;
    
    return 0;
}