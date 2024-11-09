#include <iostream> 
#include<stack>
using namespace std; 

int main() {

    //create a stack
    stack<int> s;

    //push data
    s.push(2);
    s.push(4);

    //pop data
    s.pop();

    //print top of the element
    cout << "top of the element of the stack is:" << s.top() << endl;

    //check that stack is empty or not
    if(s.empty()){
        cout << "stack is empty" << endl;
    }else{
        cout << "stack is not empty" << endl;
    }

    //size of stack
    cout << "size of stack is:" << s.size() << endl;

    return 0;
}