#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* arb;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->arb = NULL;
    }
};

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* copyList(Node* head) {
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while (temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while (originalNode != NULL && cloneNode != NULL) {
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    originalNode = head;
    cloneNode = cloneHead;
    
    while (originalNode != NULL && cloneNode != NULL) {
        if (originalNode->arb != NULL) {
            cloneNode->arb = originalNode->arb->next;
        } else {
            cloneNode->arb = NULL;
        }

        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }

    Node* original = head;
    Node* copy = cloneHead;

    while (original && copy) {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return cloneHead;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* originalList = new Node(10);
    Node* tail = originalList;
    insertAtTail(originalList, tail, 20);
    insertAtTail(originalList, tail, 30);
    insertAtTail(originalList, tail, 40);

    cout << "Original List: ";
    display(originalList);

    Node* copiedList = copyList(originalList);
    cout << "Copied List: ";
    display(copiedList);

    return 0;
}
