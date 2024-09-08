#include <iostream>

using namespace std;

// Function to search for a key in the array
int search(int arr[], int size, int key) {
    // Loop through the array to find the key
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) { // If the key is found, return 1
            return 1;
        }
    }
    return 0; // If the key is not found, return 0
}

int main() {
    // Initialize an array of size 10
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int key; // Variable to store the key to be searched
    cout << "Enter the value to search in the array: ";
    cin >> key; // Take input from the user

    // Call the search function to find the key in the array
    bool found = search(arr, 10, key);

    // Check if the value was found and print the result
    if (found) {
        cout << "Value is available in the array." << endl;
    } else {
        cout << "Value is not available in the array." << endl;
    }

    return 0;
}
