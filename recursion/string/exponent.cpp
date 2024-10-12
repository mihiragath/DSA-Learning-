#include<iostream>
using namespace std;

// Function to calculate a^b using recursion and exponentiation by squaring
int power(int a, int b) {
    // Base case: if exponent is 0, return 1
    if(b == 0)
        return 1;

    // Base case: if exponent is 1, return a
    if(b == 1)
        return a;

    // Recursive call to solve smaller subproblem
    int ans = power(a, b / 2);

    // If b is even, return ans * ans
    if(b % 2 == 0) {
        return ans * ans;
    }
    // If b is odd, return a * ans * ans
    else {
        return a * ans * ans;
    }
}

int main() {
    int a, b;
    // Input values of a and b
    cin >> a >> b;

    // Call the power function
    int ans = power(a, b);

    // Output the result
    cout << "Answer is " << ans << endl;

    return 0;
}
    