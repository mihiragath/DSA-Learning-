#include <iostream> 

using namespace std; 

class node {
public:
    int data;
    node* prev;
    node* next;

    node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtLast(node*& head, int data) {
    node* newNode = new node(data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
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
    node* head = NULL;

    insertAtLast(head, 10);
    insertAtLast(head, 25);
    display(head);
    return 0;
}
