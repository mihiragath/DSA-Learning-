#include<iostream> 
using namespace std;

// Function to calculate the factorial of a number using recursion
int factorial(int n) {
    
    // Base case: factorial of 0 is 1
    if(n == 0)
        return 1;

    // Recursive call: smaller problem is factorial(n-1)
    int smallerProblem = factorial(n - 1);   
    
    // Calculate the bigger problem by multiplying n with the result of the smaller problem
    int biggerProblem = n * smallerProblem;

    // Return the result of the bigger problem
    return biggerProblem;
}

int main() {
    int n;
    
    // Take input from the user
    cin >> n;

    // Call the factorial function and store the result in 'ans'
    int ans = factorial(n);

    // Output the factorial of the given number
    cout << ans << endl;

    return 0;
}
