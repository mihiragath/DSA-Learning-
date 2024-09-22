#include <iostream>
#include <algorithm>

using namespace std;

// Function to check if it is possible to place the cows such that the minimum distance between them is at least 'mid'
bool isPossible(int stalls[], int n, int k, int mid) {
    int cowCount = 1;        // We place the first cow in the first stall
    int lastPos = stalls[0]; // Position of the last placed cow

    // Traverse the stalls and try to place the cows
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= mid) { // Check if the current stall is at least 'mid' distance away from the last placed cow
            cowCount++;
            if (cowCount == k) {
                return true; // All cows are placed
            }
            lastPos = stalls[i]; // Update the position of the last placed cow
        }
    }
    return false; // Not possible to place all cows with at least 'mid' distance
}

// Function to find the largest minimum distance between cows
int aggressiveCows(int stalls[], int n, int k) {
    // Sort the stalls to place cows in an ordered way
    sort(stalls, stalls + n);
    
    int s = 0;
    int e = stalls[n - 1] - stalls[0]; // Maximum possible distance is the difference between the first and last stall
    int ans = -1;
    int mid = s + (e - s) / 2;
    
    // Binary search for the optimal solution
    while (s <= e) {
        if (isPossible(stalls, n, k, mid)) {
            ans = mid;       // If placing cows is possible with 'mid' distance, store the answer
            s = mid + 1;     // Try for a larger minimum distance
        } else {
            e = mid - 1;     // Try for a smaller minimum distance
        }
        mid = s + (e - s) / 2;
    }
    return ans; // Return the largest minimum distance
}

int main() {
    int stalls[] = {1, 2, 8, 4, 9}; // Example stalls positions
    int n = 5;  // Number of stalls
    int k = 3;  // Number of cows

    cout << "The largest minimum distance is: " << aggressiveCows(stalls, n, k) << endl;

    return 0;
}