#include <iostream> 

using namespace std; 

// Function to replace spaces in the input string with "@40"
string replaceSpaces(string &str){
    string temp = ""; // Temporary string to store the modified result
    
    // Loop through each character in the input string
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') { 
            // If the character is a space, append "@40" to the temp string
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            // If it's not a space, just append the original character
            temp.push_back(str[i]);
        }
    }
    
    return temp; // Return the modified string
}

int main() {
    string input = "I love coding"; // Input string

    // Call the function and print the modified string
    string result = replaceSpaces(input);
    cout << "Modified String: " << result << endl; 
    
    return 0; // Return 0 to indicate successful execution
}
