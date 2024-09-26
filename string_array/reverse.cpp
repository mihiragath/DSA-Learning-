#include <iostream>
#include <sstream>
using namespace std;

// Function to reverse a word
void reverseWord(string &word) {
    int start = 0, end = word.length() - 1;
    while (start < end) {
        swap(word[start], word[end]); // Swap the characters at start and end
        start++;
        end--;
    }
}

int main() {
    string str = "I love you";
    stringstream ss(str); // To split the words from the string
    string word;

    cout << "Original String: " << str << endl;
    cout << "Reversed Words: ";

    // Process each word
    while (ss >> word) {
        reverseWord(word);  // Reverse the current word manually
        cout << word << " ";  // Output the reversed word
    }

    cout << endl;
    return 0;
}
