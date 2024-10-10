#include<iostream>
using namespace std;

// Function to check if the array is sorted
bool isSorted(int arr[], int size) {

    // Base case: if the array has one or zero elements, it's sorted
    if(size == 0 || size == 1 ){
        return true;
    }

    // Check if the first element is greater than the second
    if(arr[0] > arr[1])
        return false;
    else {
        // Recursive call to check the remaining part of the array
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }

}

int main() {

    // Initialize the array and its size
    int arr[5] = {2, 4, 9, 9, 9};
    int size = 5;

    // Call the isSorted function
    bool ans = isSorted(arr, size);

    // Output the result
    if(ans){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}
