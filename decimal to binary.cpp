#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Input the number (either decimal or binary based on context)

    int ans = 0; // Initialize the result to store the converted number
    int i = 0;   // Initialize the position counter

    // The first part (commented) converts a decimal number to binary
    /*
    while (n != 0) {
        int bit = n & 1; // Extract the least significant bit of n

        ans = (bit * pow(10, i)) + ans; // Form the binary number by adding bits
        n = n >> 1; // Right shift the number to process the next bit
        i++;
    }
    */

    // The current loop converts binary (as integer input) to its decimal equivalent
    while (n != 0) {
        int digit = n % 10; // Extract the last digit of the binary number

        // If the digit is 1, add the corresponding power of 2 to the result
        if (digit == 1) {
            ans = ans + pow(2, i); // Calculate the decimal equivalent of the binary digit
        }

        n = n / 10; // Remove the last digit to process the next one
        i++; // Move to the next position

        // Print the current possibility of the number in decimal format
        cout << "Possibility of number in decimal is: " << ans << endl;
    }

    cout << endl;

    // Output the final result of the conversion from binary to decimal
    cout << "Final decimal answer is: " << ans << endl;

    return 0;
}
