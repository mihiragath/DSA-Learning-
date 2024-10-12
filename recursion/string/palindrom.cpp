#include <iostream> 
using namespace std; 

// Function to check if a string is a palindrome using recursion
bool palinDrom(string name, int i, int j) {
    // Base case: If the start index crosses the end index
    if(i > j)
        return true;

    // If characters at position i and j do not match, return false
    if(name[i] != name[j]) {
        return false;
    }

    // Recursive call to check the next set of characters
    return palinDrom(name, i+1, j-1);
}

int main() {
    string name = "abcbaa";

    // Call the palindrome function
    bool ans = palinDrom(name, 0, name.length()-1);

    // Output the result
    if(ans) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
