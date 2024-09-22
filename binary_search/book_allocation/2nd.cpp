#include <iostream>
#include <algorithm>
using namespace std;

// Helper function to check if the allocation is possible with the current mid value
bool isPossible(int arr[], int n, int k, int mid) {
    int painterCount = 1;  // Number of painters required
    int timeSum = 0;       // Time taken to paint boards for the current painter

    // Traverse through each board
    for (int i = 0; i < n; i++) {
        // If adding the current board exceeds mid, allocate to the next painter
        if (timeSum + arr[i] > mid) {
            painterCount++;
            timeSum = arr[i];  // Start with the current board for the new painter
            
            // If the number of painters exceeds k or a board is longer than mid, return false
            if (painterCount > k || arr[i] > mid) {
                return false;
            }
        } else {
            // Allocate the current board to the current painter
            timeSum += arr[i];
        }
    }
    return true;
}

// Main function to find the minimum time required to paint all boards
int allocateBoard(int arr[], int n, int k) {
    int s = 0;   // Start of binary search range
    int sum = 0; // Sum of all boards

    // Calculate the total sum of boards
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int e = sum;             // End of binary search range
    int ans = -1;            // To store the answer (minimum of the maximum time)
    int mid = s + (e - s) / 2;  // Calculate mid value

    // Binary search to find the optimal allocation
    while (s <= e) {
        if (isPossible(arr, n, k, mid)) {
            // If the current mid value is a possible solution, store the result
            ans = mid;
            e = mid - 1;  // Try to find a better (smaller) solution
        } else {
            s = mid + 1;  // Increase the value of mid to find a feasible solution
        }
        mid = s + (e - s) / 2;  // Recalculate mid value
    }

    return ans;  // Return the minimum possible maximum time
}

int main() {
    int arr[] = {2, 1, 5, 6, 2, 3}; // Example: lengths of the boards
    int n = sizeof(arr) / sizeof(arr[0]); // Number of boards
    int k = 2;                    // Number of painters

    cout << "Minimum time required to paint all boards: " << allocateBoard(arr, n, k) << endl;

    return 0;
}
