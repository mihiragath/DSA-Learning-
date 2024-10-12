#include <iostream>

using namespace std;

// Function to calculate the nth Fibonacci number
int fibo(int n) {
    // Base case: the 0th Fibonacci number is 0
    if(n == 0) {
        return 0;
    }

    // Base case: the 1st Fibonacci number is 1
    if(n == 1) {
        return 1;
    }

    // Recursive relation: F(n) = F(n-1) + F(n-2)
    int ans = fibo(n-1) + fibo(n-2);
    return ans;
}

int main() {
    int n;
    cout << "Enter value: ";
    cin >> n;

    // Output the nth Fibonacci number
    cout << "Fibonacci number is: " << fibo(n) << endl;
    return 0;
}
