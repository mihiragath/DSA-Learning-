/*
          +-------------------+
          |      Parent       |
          +-------------------+
                  |
                  |
                  |
                  v
          +-------------------+
          |      Child        |
          +-------------------+
*/
#include <iostream> 
#include<string>
using namespace std; 
class parent{
    public: 
        string fname = "ram";
        int fage = 40;
    
};

// inherite an parent class
class child : public parent{
    public:
        string name = "karan";
        int age=16;

    string getFname(){
        return this->fname;
    }

    string getName(){
        return this->name;
    }



};

int main() {
    child c1;
    cout << "father name is:" << c1.getFname() << endl << "father age is:" << c1.fage << endl;
    cout << "child name is:" << c1.getName() << endl << "child age is: " << c1.age << endl;
    return 0;
}