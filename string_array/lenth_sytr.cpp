#include <iostream>

using namespace std;

// Function to reverse the string
void reverse(char name[], int n) {
    int s = 0; // Start from the first character
    int e = n - 1; // End at the last character

    while (s < e) {
        swap(name[s++], name[e--]); // Swap the characters and move indices
    }
}

// Function to calculate the length of the string
int length(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    cout << "Hello, World!" << endl;
    
    char name[20];
    cout << "Enter your name: ";
    cin >> name; // Reading the name (a string)

    int len = length(name);
    cout << "Length of the string: " << len << endl;

    reverse(name, len); // Reverse the string
    cout << "Reversed string: " << name << endl; // Output the reversed string

    return 0;
}
