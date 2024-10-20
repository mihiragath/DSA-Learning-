#include <iostream>
using namespace std;

void solve(int arr[], int n, int output[], int index, int outputIndex, int ans[][10], int subsetSizes[], int& ansIndex) {
    // Base case: when the index reaches the end of the array
    if (index >= n) {
        // Copy the current subset (stored in output) to the result (ans)
        for (int i = 0; i < outputIndex; i++) {
            ans[ansIndex][i] = output[i];
        }
        subsetSizes[ansIndex] = outputIndex; // Track the size of the current subset
        ansIndex++;  // Increment the subset counter
        return;
    }

    // Exclude the current element
    solve(arr, n, output, index + 1, outputIndex, ans, subsetSizes, ansIndex);

    // Include the current element
    output[outputIndex] = arr[index];
    solve(arr, n, output, index + 1, outputIndex + 1, ans, subsetSizes, ansIndex);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;  // Size of the input array

    int ans[10][10] = {0};  // 2D array to store subsets
    int output[10] = {0};   // Temporary array to store one subset
    int subsetSizes[10] = {0}; // Array to track the size of each subset
    int ansIndex = 0;  // Tracks how many subsets we have generated

    solve(arr, n, output, 0, 0, ans, subsetSizes, ansIndex);

    // Output all the subsets
    for (int i = 0; i < ansIndex; i++) {
        cout << "{ ";
        for (int j = 0; j < subsetSizes[i]; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
