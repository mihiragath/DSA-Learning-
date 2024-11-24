#include <iostream>
#include <stack>
using namespace std;

bool checkParenthese(string expression, stack<char> &s) {
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (!s.empty()) {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    stack<char> s;
    string expression = "([{}])";
    if (checkParenthese(expression, s)) {
        cout << "Valid expression" << endl;
    } else {
        cout << "Invalid expression" << endl;
    }
    return 0;
}
