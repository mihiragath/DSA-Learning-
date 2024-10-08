#include<iostream> 
using namespace std;

// Function to print numbers from 1 to n using recursion
void print(int n) {
    // Base case: if n is 0, return to stop the recursion
    if (n == 0) {
        return;
    }

    // Recursive relation: call the print function with n-1
    print(n - 1);

    // Print the current value of n after returning from the recursive call
    cout << n << endl;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";  // Prompt user for input
    cin >> n;  // Read input value

    cout << endl;  // Print a new line for better formatting
    print(n);  // Call the print function to display numbers from 1 to n

    return 0;  // End of the program
}
