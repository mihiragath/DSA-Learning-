#include <iostream>
#include "expclass.cpp"
using namespace std;

class student {
private:
    int age = 19;
public:
    char name[6] = "Mihir";
    char surname[6] = "Agath";

    int getage() {
        return age;
    }

    void setage(int a) {
        age = a;
    }
};

int main() { 
    department std2;
    //using dynamic allocation maathod
    student *s = new student();
    s->setage(21);
    cout << "age of the student using dynamic allocatiob method is:" << s->getage() << endl;
    //using static allocatinon method
    student std;
    cout << "Student age is: " << std.getage() << endl;
    std.setage(20);
    cout << "Updated student age is: " << std.getage() << endl;
    cout << "Student name is: " << std.name << endl;
    cout << "Surname of student: " << std.surname << endl;
    cout << "Department of the student is: " << std2.depart << endl;
    cout << "SPI of student: " << std2.spi << endl;
    cout << "Current semester of student is: " << std2.sem << endl;

    return 0;
}
