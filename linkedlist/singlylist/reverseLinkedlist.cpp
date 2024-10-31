#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void reverse(node* &head) {
    if (head == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }

    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    head = prev; // Update head to the new first node
}

void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertEnd(node* &head, int data) {
    node* newNode = new node();
    newNode->data = data;
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
}

int main() {
    node* head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    
    cout << "Original list: ";
    printList(head);
    
    reverse(head);
    
    cout << "Reversed list: ";
    printList(head);
    
    return 0;
}