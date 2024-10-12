#include<iostream> 
using namespace std;

// Function to say the digits of a number
void sayDigit(int n, string arr[]) {

    // Base case: when n becomes 0, stop recursion
    if(n == 0)
        return ;

    // Extract the last digit of the number
    int digit = n % 10;
    n = n / 10;  // Remove the last digit by dividing by 10

    // Recursive call to continue processing the remaining digits
    sayDigit(n, arr);

    // Print the corresponding word for the current digit
    cout << arr[digit] << " ";

}

int main() {

    // Array to store the words for digits from 0 to 9
    string arr[10] = {"zero", "one", "two", "three",
                         "four", "five", "six"
                        , "seven", "eight", "nine"};
    
    // Input number from the user
    int n;
    cin >> n;

    cout << endl << endl << endl ;
    
    // Call the function to say the digits of the number
    sayDigit(n, arr);
    
    cout << endl << endl << endl ;

    return 0;
}
