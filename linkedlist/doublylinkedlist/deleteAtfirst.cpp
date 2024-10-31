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

void deleteAtFirst(node* &head){
    if(head == NULL){
        cout << "linked list is empty";
    }
    node* temp = head;
    head = head->next;
    delete temp;
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
    node* node1 = new node(50);
    node* head = node1;

    insertAtFirst(head, 40);
    insertAtFirst(head, 30);
    insertAtFirst(head, 20);
    cout << "before deleting node" << endl;
    display(head);
    cout << "after deleting node" << endl;
    deleteAtFirst(head);
    display(head);
    return 0;
}
