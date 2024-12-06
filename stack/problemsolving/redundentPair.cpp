#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            if (ch == ')') {
                bool isRedundant = true;

                while (st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main() {
    string expression;

    cout << "Enter the expression to check for redundant brackets: ";
    cin >> expression;

    if (findRedundantBrackets(expression)) {
        cout << "The expression contains redundant brackets." << endl;
    } else {
        cout << "The expression does not contain redundant brackets." << endl;
    }

    return 0;
}
