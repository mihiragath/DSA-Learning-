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

void insertNode(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void deleteAtLast(node*& head) {
    if (head == NULL) return;
    node* temp = head;
    temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = NULL;
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
    cout << "before delete node" << endl;
    insertNode(head, 50);
    insertNode(head, 40);
    insertNode(head, 30);
    insertNode(head, 20);
    insertNode(head, 10);
    display(head);
    cout << "after delete node" << endl;
    deleteAtLast(head);
    display(head);
    
    return 0;
}
