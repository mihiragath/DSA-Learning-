#include <iostream> 
using namespace std; 

// Recursive binary search function
bool binarySearch(int *arr, int key, int s, int e){
    // Base case: if the start index exceeds the end index, the key is not present
    if(s > e){
        return false;
    }

    // Calculate mid-point
    int mid = (s + e) / 2;

    // Check if the mid-point is the key
    if(arr[mid] == key) {
        return true;
    }

    // If the key is larger than the mid element, search in the right half
    if(arr[mid] < key){
        return binarySearch(arr, key, mid + 1, e);
    }
    // Otherwise, search in the left half
    else {
        return binarySearch(arr, key, s, mid - 1);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Array to search
    int size = 5;
    int key = 2; // Key to search for

    // Start and end indices for binary search
    int s = 0; // Start index should be 0 (not arr[0])
    int e = size - 1;

    // Perform binary search
    bool ans = binarySearch(arr, key, s, e);

    // Output result
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}
