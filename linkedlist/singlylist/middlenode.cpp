#include <iostream> 

using namespace std; 

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtstart(node* &head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void middleNode(node* head) {
    int count = 0;
    node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int middleIndex = count / 2;
    temp = head;
    for (int i = 0; i < middleIndex; i++) {
        temp = temp->next;
    }

    cout << "Middle value in linked list is: " << temp->data << endl;
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
    node* head = new node(40);
    insertAtstart(head, 30);
    insertAtstart(head, 20);
    insertAtstart(head, 10);

    cout << "Linked List: ";
    display(head);
    middleNode(head);

    node* current = head;
    while (current != NULL) {
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
