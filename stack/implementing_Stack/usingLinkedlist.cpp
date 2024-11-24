#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top;

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Push an element onto the stack
    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }

    // Pop the top element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack UnderFlow" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek at the top element of the stack
    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Main function to test the stack
int main() {
    Stack st;

    st.push(23);
    st.push(21);
    st.push(20);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if (st.isEmpty()) {
        cout << "Stack is Empty mere dost" << endl;
    } else {
        cout << "Stack is not Empty mere dost" << endl;
    }

    return 0;
}
