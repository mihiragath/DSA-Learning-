/*
          +-------------------+
          |      Person       |
          +-------------------+
                  |
                  |
                  v
          +-------------------+
          |     University     |
          +-------------------+
                  |
                  |
                  v
          +-------------------+
          |      Student      |
          +-------------------+
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name; // Made private for encapsulation

public:
    // Getter and setter for name
    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }
};

class University : public Person { // University inherits from Person
private:
    string university; // Made private for encapsulation

public:
    // Getter and setter for university
    string getUniversity() const {
        return university;
    }

    void setUniversity(const string& u) {
        university = u;
    }
};

class Student : public University { // Student inherits from University
public:
    string course = "Computer Science"; // Existing variable
    string studentID = "cs1"; // Existing variable

    void display() {
        cout << "Student name is: " << getName() << endl; // Using Person's getter
        cout << "Student university name is: " << getUniversity() << endl; // Using University’s getter
        cout << "Student course is: " << course << endl; // Display existing variable
        cout << "Student ID is: " << studentID << endl; // Display existing variable
    }
};

int main() {
    Student s1;

    // Setting values using getters and setters
    s1.setName("Mihir");         // Setting name in Person
    s1.setUniversity("GTU");     // Setting university in University
    
    s1.display(); // Display all information

    return 0;
}
