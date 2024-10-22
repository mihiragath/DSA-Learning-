#include <iostream> 

using namespace std; 

class student{
    public:
    static int id;
    

};

int student :: id=5;

int main() {
    student s;
    cout << "id of student :" << s.id << endl;
    return 0;
}