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

//using vactor array

/*
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>& ans) {
    // Base case: when index goes beyond the size of nums
    if (index >= nums.size()) {
        ans.push_back(output);  // Add the current subset to the answer
        return;
    }
    
    // Exclude the current element and move to the next
    solve(nums, output, index + 1, ans);
    
    // Include the current element in the subset
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;  // To store all subsets
    vector<int> output;       // To store the current subset
    int index = 0;            // Start from the first element
    solve(nums, output, index, ans);  // Call the recursive function
    return ans;               // Return the result
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> subsetsResult = subsets(nums);
    
    // Output all the subsets
    for (auto subset : subsetsResult) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

*/
