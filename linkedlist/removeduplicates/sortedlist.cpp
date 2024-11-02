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

void removeDuplicates(node* head) {
    node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}

void disply(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;

    insertAtstart(head, 20);
    insertAtstart(head, 20);
    insertAtstart(head, 30);
    insertAtstart(head, 30);
    insertAtstart(head, 40);

    removeDuplicates(head);
    disply(head);

    return 0;
}
