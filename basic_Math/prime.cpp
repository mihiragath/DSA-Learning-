#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    // Numbers less than or equal to 1 are not prime
    if (n <= 1) {
        return false;
    }

    // Check for divisibility from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true; // If no divisors found, it's a prime number
}

// Function to count the number of prime numbers less than 'n'
int countPrimes(int n) {
    int count = 0;

    // Loop through all numbers from 2 to n-1
    for (int i = 2; i < n; i++) {
        // If the number is prime, increment the counter
        if (isPrime(i)) {
            count++;
        }
    }
    return count; // Return the total count of prime numbers
}

int main() {
    int n;
    
    // Take input from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    // Count the number of primes less than 'n'
    int primeCount = countPrimes(n);
    
    // Output the result
    printf("Number of primes less than %d: %d\n", n, primeCount);

    return 0;
}
