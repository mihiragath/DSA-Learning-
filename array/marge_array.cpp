#include <iostream> 

using namespace std; 

// Function to merge two sorted arrays into a third array
void merge(int arr1[], int arr2[], int arr3[], int m, int n) {
    int i = 0, j = 0, k = 0;  // Initialize index variables for arr1, arr2, and arr3

    // Merge elements of arr1 and arr2 into arr3
    while (i < n && j < m) {
        // If the current element of arr1 is smaller, add it to arr3
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];  // Add arr1[i] to arr3 and increment i and k
        } else {
            arr3[k++] = arr2[j++];  // Otherwise, add arr2[j] to arr3 and increment j and k
        }
    }

    // If there are any remaining elements in arr1, add them to arr3
    while (i < n) {
        arr3[k++] = arr1[i++];  // Add the rest of arr1 to arr3 and increment i and k
    }

    // If there are any remaining elements in arr2, add them to arr3
    while (j < m) {
        arr3[k++] = arr2[j++];  // Add the rest of arr2 to arr3 and increment j and k
    }
}

int main() {
    int arr1[] = {1, 3, 5};  // First sorted array
    int arr2[] = {2, 4, 6};  // Second sorted array
    int n = sizeof(arr1) / sizeof(arr1[0]);  // Size of arr1
    int m = sizeof(arr2) / sizeof(arr2[0]);  // Size of arr2
    int arr3[n + m];  // Array to hold the merged elements

    // Call the merge function to merge arr1 and arr2 into arr3
    merge(arr1, arr2, arr3, m, n);

    // Print the merged array
    cout << "Merged array: ";
    for (int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";  // Print each element of arr3
    }
    cout << endl;

    return 0;  // Exit the program
}
