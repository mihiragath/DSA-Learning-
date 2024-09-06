#include <iostream>
using namespace std;

int main() {
    int totalAmount;  // Total amount in rupees
    int choice;  // User's choice

    // Ask the user to enter the total amount
    cout << "Enter the total amount in rupees: ";
    cin >> totalAmount;

    cout << "Select an option to find out how many notes or coins are required:\n";
    cout << "1. Number of 100 rupee notes\n";
    cout << "2. Number of 20 rupee notes\n";
    cout << "3. Number of 1 rupee coins\n";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Number of 100 rupee notes required: " << totalAmount / 100 << endl;
            break;

        case 2:
            cout << "Number of 20 rupee notes required: " << totalAmount / 20 << endl;
            break;

        case 3:
            cout << "Number of 1 rupee coins required: " << totalAmount / 1 << endl;
            break;

        default:
            cout << "Invalid choice, exiting." << endl;
            break;
    }

    return 0;
}
