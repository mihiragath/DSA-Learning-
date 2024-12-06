#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    if (stack.empty() || stack.top() < num) {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack) {
    if (stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, num);
}

void printStack(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stack;

    stack.push(10);
    stack.push(30);
    stack.push(5);
    stack.push(40);
    cout << "before sorted value:" << endl;
    printStack(stack);
    
    sortStack(stack);
    cout << "after sorted value:" << endl;
    printStack(stack);

    return 0;
}
