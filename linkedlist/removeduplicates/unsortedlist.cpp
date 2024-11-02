/*
    1st approach:-
        1st approach is said that the one node is compare with all node which will inside the linked list and short the lost.

        2nd approach:-
            2nd approach is said that the 1st short linked lost and then remove an duplicates form then list.

        3rd approach:-
            3rd approach is said that first map the linked list element and then remove the duplicates from the linked list...
*/
#include <iostream>
#include <map>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) : data(data), next(NULL) {}
};

void insertAtStart(node* &head, int data) {
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

void removeDuplicates(node* &head) {
    if (!head) return;

    map<int, bool> seen;
    node* current = head;
    node* prev = NULL;

    while (current) {
        if (seen[current->data]) {
            prev->next = current->next;
            delete current;
        } else {
            seen[current->data] = true;
            prev = current;
        }
        current = prev->next;
    }
}

void display(node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    insertAtStart(head, 10);
    insertAtStart(head, 30);
    insertAtStart(head, 30);
    insertAtStart(head, 40);
    insertAtStart(head, 20);
    insertAtStart(head, 10);

    removeDuplicates(head);
    display(head);

    return 0;
}
