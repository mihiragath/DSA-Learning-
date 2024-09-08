#include <iostream>
#include <climits> // Include for INT_MIN and INT_MAX

using namespace std;

// Function to find the maximum value in an array
int getMax(int num[], int n) {
    int maxi = INT_MIN; // Initialize with the smallest possible integer

    for (int i = 0; i < n; i++) {
        // Update maxi to the maximum value between current maxi and num[i]
        maxi = max(maxi, num[i]);
        // Alternatively, using an if statement:
        // if (num[i] > maxi) {
        //     maxi = num[i];
        // }
    }
    return maxi;
}

// Function to find the minimum value in an array
int getMin(int num[], int n) {
    int mini = INT_MAX; // Initialize with the largest possible integer

    for (int i = 0; i < n; i++) {
        // Update mini to the minimum value between current mini and num[i]
        mini = min(mini, num[i]);
        // Alternatively, using an if statement:
        // if (num[i] < mini) {
        //     mini = num[i];
        // }
    }
    return mini;
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

    // Print the maximum value of the array
    cout << "Maximum value of the array: " << getMax(num, size) << endl;
    // Print the minimum value of the array
    cout << "Minimum value of the array: " << getMin(num, size) << endl;

    return 0;
}
