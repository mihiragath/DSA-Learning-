#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtStart(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void beforeSpecificPos(node*& head, int data, int val) {
    node* Newnode = new node(data);
    if (head == NULL) {
        head = Newnode;
        return;
    }
    if (head->data == val) {
        Newnode->next = head;
        head->prev = Newnode;
        head = Newnode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        delete Newnode;
        return;
    }
    Newnode->next = temp->next;
    Newnode->prev = temp;
    temp->next->prev = Newnode;
    temp->next = Newnode;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void afterSpecificPos(node*& head, int data, int val) {
    node* Newnode = new node(data);
    if (head == NULL) {
        head = Newnode;
        return;
    }
    node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        delete Newnode;
        return;
    }
    Newnode->next = temp->next;
    Newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = Newnode;
    }
    temp->next = Newnode;
}

int main() {
    node* head = NULL;
    cout << "inser before specific position which value is 25" << endl;
    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);
    insertAtStart(head, 40);
    insertAtStart(head, 50);
    beforeSpecificPos(head, 25, 20);
    display(head);
    cout << "inser after specific position which value is 35" << endl;
    afterSpecificPos(head, 35, 40);
    display(head);
    
    return 0;
}
