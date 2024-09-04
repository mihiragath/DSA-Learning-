#include <iostream>
using namespace std;

int main() {
    int n; // Declare an integer variable `n` to store the user's input
    cout << "Enter the value of n: " << endl; // Prompt the user to enter a number
    cin >> n; // Read the input value and store it in `n`

    bool isprime = 1; // Initialize a boolean variable `isprime` to true (1), assuming `n` is prime

    // Loop to check if `n` has any divisors other than 1 and itself
    for (int i = 2; i < n; i++) { // Start loop from 2 up to n-1
        if (n % i == 0) { // Check if `n` is divisible by `i`
            isprime = 0; // If `n` is divisible by `i`, set `isprime` to false (0)
            break; // Exit the loop early since `n` is not a prime number
        }
    }

    // Check the value of `isprime` to determine if `n` is a prime number
    if (isprime == 0) { // If `isprime` is false, then `n` is not a prime number
        cout << "Not a prime number" << endl;
    } else { // If `isprime` is true, then `n` is a prime number
        cout << "Is a prime number" << endl;
    }
    
    return 0; // Return 0 to indicate successful execution of the program
}
