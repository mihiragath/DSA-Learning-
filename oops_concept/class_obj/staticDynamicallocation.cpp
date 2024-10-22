#include <iostream>
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
    //using dynamic allocation maathod
    student *s = new student();
    s->setage(21);
    cout << "age of the student using dynamic allocatiob method is:" << s->getage() << endl;

    //using static allocatinon method
    student std;
    cout << "Student age is: " << std.getage() << endl;
    std.setage(20);
    cout << "Student age is: " << std.getage() << endl;


    return 0;
}
