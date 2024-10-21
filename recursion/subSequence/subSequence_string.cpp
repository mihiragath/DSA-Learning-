#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& str, vector<string> output, int index, vector<vector<string>>& ans) {
    // Base case: when index goes beyond the size of str
    if (index >= str.size()) {
        ans.push_back(output);  // Add the current subset to the answer
        return;
    }
    
    // Exclude the current element and move to the next
    solve(str, output, index + 1, ans);
    
    // Include the current element in the subset
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<vector<string>> subsets(vector<string>& str) {
    vector<vector<string>> ans;  // To store all subsets
    vector<string> output;       // To store the current subset
    int index = 0;               // Start from the first element
    solve(str, output, index, ans);  // Call the recursive function
    return ans;                  // Return the result
}

int main() {
    vector<string> str = {"a", "b", "c"};  // Input strings
    
    vector<vector<string>> subsetsResult = subsets(str);
    
    // Output all the subsets
    for (auto subset : subsetsResult) {
        cout << "{ ";
        for (auto s : subset) {
            cout << s << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
