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

void insertAtstart(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void beforeSpecificpos(node*& head, int data, int val) {
    node* Newnode = new node(data);

    if (head == NULL) {
        head = Newnode;
        return;
    }

    if (head->data == val) {
        Newnode->next = head;
        head = Newnode;
        return;
    }

    node* temp = head;

    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        delete Newnode; // Clean up memory if not inserted
        return;
    }

    Newnode->next = temp->next;
    temp->next = Newnode;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Print newline for better formatting
}

void afterSpecificpos(node*& head, int data, int val) {
    node* Newnode = new node(data);

    if (head == NULL) {
        head = Newnode;
        return;
    }

    if (head->data == val) {
        Newnode->next = head;
        head = Newnode;
        return;
    }

    node* temp = head;

    while (temp->next != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        delete Newnode; // Clean up memory if not inserted
        return;
    }

    Newnode->next = temp->next;
    temp->next = Newnode;
}


int main() {
    node* head = NULL;
    cout << "insert before specific position onn link list which is 25" << endl;
    insertAtstart(head, 10);
    insertAtstart(head, 20);
    insertAtstart(head, 30);
    insertAtstart(head, 40);
    insertAtstart(head, 50);

    beforeSpecificpos(head, 25, 20);
    display(head);
    cout << "insert after apecific position on linked list which is 35" << endl;
    afterSpecificpos(head,35,40);
    display(head);
    
    return 0;
}
