/*
    another typ of polymorphism

    2]run tym polymorphism
        it called as a dynamil polymorphism
        ->method/function overriding
        it completely depens upon inheritance
        function name must be same

*/

#include <iostream> 
#include <string>
using namespace std; 

// Base class representing an animal
class animal {
public:
    // Method for speaking, implemented in the base class
    void speak() {
        cout << "speaking" << endl;
    }
};

// Derived class representing a dog, inheriting from animal
class dog : public animal { // Use public inheritance
public:
    // Method for speaking, overriding the base class method
    void speak() {
        cout << "barking" << endl;
    }
};

int main() {
    // Create an instance of the dog class
    dog d1;
    // Call the speak method, which will use the dog class's implementation
    d1.speak();
    return 0;
}
