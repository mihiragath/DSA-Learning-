#include <iostream>
using namespace std;

class student {
public:
    char grade = 'A'; // Default grade
    float spi = 9.07; // Default SPI

    // Default constructor
    student() {
        cout << "grade is: " << grade << endl;
        cout << "spi is: " << spi << endl;
    }

    // Parameterized constructor
    student(char g, float s) {
        grade = g;
        spi = s;
    }

    // Copy constructor
    student(student& temp) {
        this->grade = temp.grade;
        this->spi = temp.spi;
    }

    // Method to print grade and SPI
    void print() {
        cout << "grade is: " << grade << endl;
        cout << "spi is: " << spi << endl;
    }

    ~student(){
        cout << "distructor bhai welcome apko call kia gya hai aa jao ;)" << endl;
    }
    /*
    jo bhi constructor static allocate hota hai us kelie distructor automaticaly called ho jata hai
    */
};

int main() {
    // Call default constructor
    student s1;

    // Call parameterized constructor
    student s('B', 7.7);
    s.print();

    // Call copy constructor
    student r(s);
    r.print();

    //copy assignment operator
    s1=r;
    s1.print();
    r.print();
    return 0;
}
