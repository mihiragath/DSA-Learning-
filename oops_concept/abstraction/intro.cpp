/*
 providing only the essential details to the outside world and hiding the internal details,
 i.e., hiding the background details or implementation. Abstraction is a programming technique that depends on the separation of the interface and implementation details of the program.
*/


#include <iostream>
using namespace std;

class implementAbstraction {
private:
    int a, b; // Private members to hold values

public:
    // Method to set values of a and b
    void set(int x, int y) {
        a = x;
        b = y;
    }

    // Method to display the values of a and b
    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

int main() {
    implementAbstraction obj; // Create an object of the class
    obj.set(10, 20);          // Set values for a and b
    obj.display();            // Display the values
    return 0;
}
