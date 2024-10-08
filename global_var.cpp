#include<iostream>
using namespace std;

int score = 15;  // Global variable 'score', accessible in all functions

// Function 'a' which accepts an integer reference as parameter
void a(int& i) {
    // Print the current value of 'score' and indicate it is inside function 'a'
    cout << score << " in a" << endl;
    // Increment the global 'score' variable
    score++;
    // Declare a local character variable 'ch'
    char ch = 'a';
    // Print the value of 'i' passed by reference
    cout << i << endl;
}

// Function 'b' which accepts an integer reference as parameter
void b(int& i) {
    // Print the current value of 'score' and indicate it is inside function 'b'
    cout << score << " in b" << endl;
    // Print the value of 'i' passed by reference
    cout << i << endl;
}

int main() {
    // Print the initial value of 'score' in the main function
    cout << score << " in main" << endl;
    // Declare an integer variable 'i' with value 5
    int i = 5;
    // Call function 'a' and pass 'i' by reference
    a(i);
    // Call function 'b' and pass 'i' by reference
    b(i);

    return 0;
}
