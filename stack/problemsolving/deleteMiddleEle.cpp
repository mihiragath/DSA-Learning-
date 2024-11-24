#include <iostream>
#include <stack>
using namespace std;

void deleteAtmiddle(stack<int> &s, int count, int size) {
    if (count == size / 2) {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    deleteAtmiddle(s, count + 1, size);
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
    int count = 0;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Stack before deleting middle value: ";
    printStack(s);

    deleteAtmiddle(s, count, s.size());

    cout << "Stack after deleting middle element: ";
    printStack(s);

    return 0;
}
