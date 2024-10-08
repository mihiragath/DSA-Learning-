#include<iostream>
using namespace std;

// Inline function to return the maximum of two numbers
// Takes two integers by reference as parameters
inline int getMax(int& a, int& b) {
    // Ternary operator to check if 'a' is greater than 'b'
    // Returns 'a' if true, otherwise returns 'b'
    return (a > b) ? a : b;
}

int main() {

    int a = 1, b = 2;  // Initialize two integers
    int ans = 0;  // Variable to store the result

    // Call the inline function to get the maximum of 'a' and 'b'
    ans = getMax(a, b);
    // Output the result
    cout << ans << endl;

    // Modify the values of 'a' and 'b'
    a = a + 3;  // Increment 'a' by 3
    b = b + 1;  // Increment 'b' by 1

    // Call the inline function again to get the new maximum of 'a' and 'b'
    ans = getMax(a, b);
    // Output the result
    cout << ans << endl;

    return 0;  // End of the program
}
