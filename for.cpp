#include <iostream>
using namespace std;

int main() {
    int i, a, b, n; // Declare integer variables

    cout << "Enter value: " << endl;

    /*
    cin >> n; // Input the value for `n`

    i = 1; // Initialize `i` to 1

    // This loop initializes `i` to 1 and intended to run until `i` is less than `n`,
    // but the semicolon after the `for` makes it an empty loop:
    // for (i = 1; i < n; i++);

    // This infinite loop runs until `i` reaches `n`
    for (; ; ) { 
        if (i < n) { // Check if `i` is less than `n`
            cout << "Value: " << i << endl; // Print the value of `i`
        } else {
            break; // Break the loop when `i` is no longer less than `n`
        }
        i++; // Increment `i` by 1
    }
    */

    // This loop starts with `a = 0` and `b = 1`
    // The condition `a > 1 && b > 2` is false initially, so this loop will not execute.
    for (a = 0, b = 1; a > 1 && b > 2; a--, b--) {
        cout << a << " " << b << endl; // This line would print `a` and `b` values if the loop runs
    }

    return 0; // Return 0 to indicate successful execution of the program
}
