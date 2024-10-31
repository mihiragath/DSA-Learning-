#include <iostream> 

using namespace std; 

class node {
public:
    node* prev;
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtFirst(node*& head, int data) {
    node* temp = new node(data);
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL) {
        head->prev = temp;
    }

    head = temp;
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
    node* node1 = new node(10);
    node* head = node1;

    insertAtFirst(head, 5);
    display(head);
    return 0;
}
