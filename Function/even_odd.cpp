#include <iostream>
using namespace std;

// Function to check if a number is even or odd using bitwise AND operator
bool isEven(int num) {
    return !(num & 1);  // Returns true if the last bit is 0 (even), false otherwise (odd)
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isEven(number)) {
        cout << number << " is even." << endl;
    } else {
        cout << number << " is odd." << endl;
    }

    return 0;
}
