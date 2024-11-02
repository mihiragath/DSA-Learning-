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
    int zeroCounter = 0;
    int oneCounter = 0;
    int twoCounter = 0;

    node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) {
            zeroCounter++;
        } else if (temp->data == 1) {
            oneCounter++;
        } else if (temp->data == 2) {
            twoCounter++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (zeroCounter > 0) {
            temp->data = 0;
            zeroCounter--;
        } else if (oneCounter > 0) {
            temp->data = 1;
            oneCounter--;
        } else if (twoCounter > 0) {
            temp->data = 2;
            twoCounter--;
        }
        temp = temp->next;
    }
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
