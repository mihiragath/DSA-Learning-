#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void kReverse(node* &head, int k) {
    if (head == NULL) {
        return;
    }
    
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count = 0;
    
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if (next != NULL) {
        head->next = next;
        kReverse(head->next, k);
    }
    
    head = prev;
}

void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtStart(node* &head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

int main() {
    node* head = NULL;
    insertAtStart(head, 4);
    insertAtStart(head, 3);
    insertAtStart(head, 2);
    insertAtStart(head, 1);
    
    cout << "Original list: ";
    printList(head);
    
    kReverse(head, 2);
    
    cout << "Reversed list: ";
    printList(head);
    
    return 0;
}
