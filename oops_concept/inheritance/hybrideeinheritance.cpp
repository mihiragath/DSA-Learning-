/*
           +-------------------+
          |      Person       |
          +-------------------+
                 /  \
                /    \
               /      \
              /        \
             /          \
     +----------------+   +----------------+
     |   University   |   |     Course     |
     +----------------+   +----------------+
                \           /
                 \         /
                  \       /
                   \     /
                    \   /
                     \ /
                  +----------------+
                  |     Student     |
                  +----------------+
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

class Course : public Person { // Course also inherits from Person
private:
    string courseName; // Made private for encapsulation

public:
    // Getter and setter for course name
    string getCourseName() const {
        return courseName;
    }

    void setCourseName(const string& c) {
        courseName = c;
    }
};

class Student : public University, public Course { // Student inherits from both University and Course
public:
    string studentID = "cs1"; // Existing variable

    void display() {
        cout << "Student name is: " << University::getName() << endl; // Specify University to avoid ambiguity
        cout << "Student university name is: " << getUniversity() << endl; // Using University’s getter
        cout << "Student course name is: " << getCourseName() << endl; // Using Course's getter
        cout << "Student ID is: " << studentID << endl; // Display existing variable
    }
};

int main() {
    Student s1;

    // Setting values using getters and setters
    s1.University::setName("Mihir");         // Specify University to set name
    s1.setUniversity("GTU");                  // Setting university in University
    s1.setCourseName("Computer Science");     // Setting course name in Course
    
    s1.display(); // Display all information

    return 0;
}
