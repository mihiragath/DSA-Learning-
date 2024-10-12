#include <iostream> 
#include <string>
using namespace std; 

// Function to reverse the string using recursion
void reverseStr(string &str, int i, int j) {
    // Base case: Stop when i >= j
    if(i >= j) {
        return;
    }

    // Swap characters at position i and j
    swap(str[i], str[j]);

    // Recursive call for the remaining part
    reverseStr(str, i + 1, j - 1);
}

int main() {
    string str = "abcde";
    
    // Call reverse function
    reverseStr(str, 0, str.length() - 1);

    // Output the reversed string
    cout << "Reversed string is: " << str << endl;
    
    return 0;
}   
