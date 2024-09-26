#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string &str) {
    string temp = "";  // Temporary string to store the modified result

    // Loop through each character of the string
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            // If the current character is a space, append "@40" to the temp string
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } else {
            // If not a space, append the current character as is
            temp.push_back(str[i]);
        }
    }

    return temp;  // Return the modified string
}

int main() {
    string str = "I love programming";  // Example input string

    cout << "Original String: " << str << endl;

    // Call the replaceSpaces function and store the result
    string result = replaceSpaces(str);

    // Output the result
    cout << "Modified String: " << result << endl;

    return 0;
}
