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

void insertNode(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void afterSpecificPos(node*& head, int val) {
    if (head == NULL) {
        cout << "empty" << endl;
        return;
    }
    if (head->data == val) {
        node* toDelete = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        cout << "deleted node is: " << toDelete->data << endl;
        delete toDelete;
        return;
    }
    node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        return;
    }
    node* toDelete = temp->next;
    if (toDelete != NULL) {
        temp->next = toDelete->next;
        if (toDelete->next != NULL) {
            toDelete->next->prev = temp;
        }
        cout << "deleted node is: " << toDelete->data << endl;
        delete toDelete;
    }
}

void beforeSpecificPos(node*& head, int val) {
    if (head == NULL) {
        cout << "empty" << endl;
        return;
    }
    if (head->data == val) {
        node* toDelete = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete toDelete;
        return;
    }
    node* temp = head;
    while (temp->next != NULL && temp->next->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        return;
    }
    node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    cout << "deleted node is: " << toDelete->data << endl;
    delete toDelete;
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
    cout << "delete after specific position at 30" << endl;
    insertNode(head, 50);
    insertNode(head, 40);
    insertNode(head, 30);
    insertNode(head, 20);
    insertNode(head, 10);
    display(head);
    afterSpecificPos(head, 30);
    cout << "delete before specific position at 30" << endl;
    beforeSpecificPos(head, 30);
    display(head);
    return 0;
}
