#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    pushAtBottom(s, element);
    s.push(num);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int element = 5;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Before adding value to stack:" << endl;
    printStack(s);
    pushAtBottom(s, element);
    cout << "After adding value at bottom:" << endl;
    printStack(s);
    return 0;
}
