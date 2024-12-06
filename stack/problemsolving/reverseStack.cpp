#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(num);
}

void revStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    revStack(s);
    insertAtBottom(s, num);
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

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "before reversing stack:" << endl;
    printStack(s);

    revStack(s);
    cout << "after reversing stack:" << endl;
    printStack(s);

    return 0;
}
