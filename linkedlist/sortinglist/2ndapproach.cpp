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

node* sortList(node* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* zeroHead = new node(-1);
    node* oneHead = new node(-1);
    node* twoHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneTail = oneHead;
    node* twoTail = twoHead;

    node* current = head;
    while (current != NULL) {
        if (current->data == 0) {
            zeroTail->next = current;
            zeroTail = current;
        } else if (current->data == 1) {
            oneTail->next = current;
            oneTail = current;
        } else if (current->data == 2) {
            twoTail->next = current;
            twoTail = current;
        }
        current = current->next;
    }

    // Combine the lists
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    // Clean up dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
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
    node* node1 = new node(0);
    node* head = node1;

    insertAtstart(head, 2);
    insertAtstart(head, 2);
    insertAtstart(head, 1);
    insertAtstart(head, 0);
    insertAtstart(head, 1);

    cout << "Before sorting the list:" << endl;
    disply(head);

    sortList(head);

    cout << "After sorting the list:" << endl;
    disply(head);

    return 0;
}
