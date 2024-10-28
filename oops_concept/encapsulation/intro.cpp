/*
1] what is encapsulation?
=> A wrapping of data members & function it's call encapsulation..

use to hiding a data & hiding an information..
used in unit testing
*/
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    //by default it is private so don't need to define erticularly
    string name = "Rohan";
    int age = 19;
    int sem = 3;

public:
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

int main() {
    Student s1;

    cout << "Name is: " << s1.getName() << endl;
    cout << "Age is: " << s1.getAge() << endl;

    return 0;
}
