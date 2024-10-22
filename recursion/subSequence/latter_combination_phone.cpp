#include <iostream>
#include <vector>
using namespace std;

void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
    // Base case: If the index is beyond the length of the digit string
    if (index >= digit.length()) {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';  // Convert the char digit to an int
    string value = mapping[number];   // Get the corresponding string for the digit

    // Loop through the characters in the string mapped to the digit
    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);    // Add the character to the current output
        solve(digit, output, index + 1, ans, mapping);  // Recursive call for next digit
        output.pop_back();             // Backtrack and remove the last character
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;  // To store all combinations

    // Edge case: If the input is empty, return an empty vector
    if (digits.length() == 0) {
        return ans;
    }

    string output;
    int index = 0;
    // Mapping for digits 0-9 to corresponding strings
    string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Start the recursive function
    solve(digits, output, index, ans, mapping);
    return ans;  // Return the result
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    // Print the result
    for (string combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
