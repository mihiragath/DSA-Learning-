#include <iostream> 
using namespace std; 

// Function to calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate nCr (combinations)
int nCr(int n, int r) {
    int num = factorial(n);
    int denom = factorial(r) * factorial(n - r);
    int ans = num / denom;
    return ans;
}

int main() {
    int r, n;

    cout << "Enter values for n and r: ";
    cin >> n >> r;

    cout << "nCr is: " << nCr(n, r) << endl;

    return 0;
}
