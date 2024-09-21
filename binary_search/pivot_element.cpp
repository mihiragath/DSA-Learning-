#include <iostream>

using namespace std; 

// Function to find the pivot element (smallest element) in a rotated sorted array
int getPivot(int arr[], int n) {
    int s = 0;                     // Starting index
    int e = n - 1;                 // Ending index
    
    // Calculate the middle index
    int mid = s + (e - s) / 2;     // Initial mid value

    // Loop until start and end converge (when start == end, pivot is found)
    while (s < e) {
        // If the middle element is greater than or equal to the first element,
        // this means the smallest element lies in the right half of the array
        if (arr[mid] >= arr[0]) {
            s = mid + 1;           // Move start to mid + 1 (focus on the right half)
        } 
        // Otherwise, the smallest element lies in the left half
        else {
            e = mid;               // Move end to mid (focus on the left half)
        }

        // Recalculate the middle index after adjusting start or end
        mid = s + (e - s) / 2;
    }

    // When the loop ends, start (or end) will point to the pivot element
    return s;
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3};   // Rotated sorted array
    int n = 5;                      // Size of the array

    // Call getPivot function and print the pivot index
    cout << "Pivot element is at index: " << getPivot(arr, n) << endl;

    return 0;
}
