#include <iostream> 

using namespace std; 

class node {
public:
    node* prev;
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtFirst(node*& head, int data) {
    node* temp = new node(data);
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL) {
        head->prev = temp;
    }

    head = temp;
}

void reverse(node*& head) {
    if (head == NULL) {
        cout << "empty" << endl;
        return;
    }

    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(30);
    node* head = node1;
    cout << "before reversing node" << endl;
    insertAtFirst(head, 20);
    insertAtFirst(head, 10);
    display(head);
    cout << "after reversing node" << endl;
    reverse(head);
    display(head);
    return 0;
}
