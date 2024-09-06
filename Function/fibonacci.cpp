#include <iostream>
using namespace std;

// Function to print Fibonacci series up to n terms
void printFibonacci(int n) {
    int first = 0, second = 1, next;

    cout << "Fibonacci Series: " << first << ", " << second;

    for (int i = 3; i <= n; i++) {
        next = first + second;
        cout << ", " << next;
        first = second;
        second = next;
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    if (n >= 1) {
        printFibonacci(n);
    } else {
        cout << "Please enter a positive integer." << endl;
    }

    return 0;
}
