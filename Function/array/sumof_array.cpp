#include <iostream>

using namespace std;

// Function to calculate the sum of all elements in the array
int getSum(int num[], int n) {
    int sum = 0; // Initialize sum to 0

    for (int i = 0; i < n; i++) {
        sum += num[i]; // Add each element to the sum
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size; // Read the size of the array from the user

    int num[100]; // Declare an array to store up to 100 integers

    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> num[i]; // Read array elements from the user
    }

    // Print the sum of all elements in the array
    cout << "Sum of all elements in the array: " << getSum(num, size) << endl;

    return 0;
}
