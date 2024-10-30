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


void disply(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    node* node1 = new node(10);
    //cout << node1->data << endl;
    //cout << node1->next << endl;

    node* head = node1;

    insertAtstart(head, 20);
    disply(head);

    return 0;
}
