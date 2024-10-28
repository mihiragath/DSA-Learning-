/*
    poly means many and morph means forms..
    there are 2 tyopes of polymorphism:- 1]compile tym 2] rum tym polymorphism

    1]compile tym:-
        cllead static polymorphism
        there are devide 2 parts
            1]function overloading 
            2]operator overloading
*/

#include <iostream> 
#include <string>
using namespace std; 

class student {
public:
    string n;

    // Function overloading
    void sayHello() {
        cout << "Hello Mihir!" << endl;
    }

    void sayHello(string n) {
        cout << "Hello " << n << "!" << endl;
    }
};

class B {
public:
    int a;
    int b;

    // Method to add a and b
    int add() {
        return a + b;
    }

    // Operator overloading for +
    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
        cout << "Hello Mihir" << endl;
    }
};

int main() {
    // Function overloading demonstration
    student s1;
    s1.sayHello();

    // Operator overloading demonstration
    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2; // Calls the overloaded + operator
    return 0;
}
