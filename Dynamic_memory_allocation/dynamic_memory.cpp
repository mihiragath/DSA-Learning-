#include<iostream>
using namespace std;

// Function to calculate the sum of elements in the array
int getSum(int *arr, int n) {

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];  // Add each element to sum
    }
    return sum;
}

int main() {

    int n;  // Variable to store size of the array
    cin >> n;  // Input size of the array
    
    // Dynamically allocate an array of size n
    int* arr = new int[n];

    // Taking input for array elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the sum of the array elements using the getSum function
    int ans = getSum(arr, n);

    // Output the sum
    cout << "Answer is " << ans << endl;

    // Case 1: Infinite loop where 'i' is declared but does not cause a memory leak
    while(true) {
        int i = 5;  // No memory leak since 'i' is local to the loop and is destroyed after each iteration
    }
    
    // Case 2: Infinite loop causing a memory leak due to allocation without deallocation
    while(true) {
        int* ptr = new int;  // Memory leak: no deletion (delete ptr;) to free memory
    }

    // Free dynamically allocated memory for the array
    delete[] arr;

    return 0;
}
