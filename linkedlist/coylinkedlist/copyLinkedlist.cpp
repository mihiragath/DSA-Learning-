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

void insertAtEnd(node* &head, int data) {
    node* temp = new node(data);
    if (head == NULL) {
        head = temp;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

node* copyList(node* head) {
    if (head == NULL) return NULL;

    node* copyHead = new node(head->data);
    node* currentOriginal = head->next;
    node* currentCopy = copyHead;

    while (currentOriginal != NULL) {
        node* newNode = new node(currentOriginal->data);
        currentCopy->next = newNode;
        currentCopy = newNode;
        currentOriginal = currentOriginal->next;
    }

    return copyHead;
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
    node* originalList = new node(10);
    insertAtEnd(originalList, 20);
    insertAtEnd(originalList, 30);
    insertAtEnd(originalList, 40);

    cout << "Original List: ";
    display(originalList);

    node* copiedList = copyList(originalList);
    cout << "Copied List: ";
    display(copiedList);

    return 0;
}
