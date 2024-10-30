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

void insertNode(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void afterSpecificPos(node*& head, int val) {
    if (head == NULL) {
        cout << "empty" << endl;
        return;
    }
   
    if (head->data == val) {
        node* toDelete = head;
        head = head->next;
        cout << "deleted node is: " << toDelete->data << endl;
        delete toDelete;
        return;
    }

    node* temp = head;

    while (temp->next != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        return;
    }
    
    node* toDelete = temp->next;
    temp->next = toDelete->next;
    cout << "deleted node is: " << toDelete->data << endl;
    delete toDelete;
}

void beforeSpecificPos(node* head, int val){
    if(head  == NULL){
        cout << "empty";
        return;
    }
    if(head->data == val){
        node* TOdel = head;
        head = head->next;
        delete TOdel;
    }

    node* temp = head;
    
    if(temp->next != NULL && temp->next->data == val){
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Value " << val << " not found in list." << endl;
        return;
    }
    node* Todel = temp;
    Todel = Todel->next;
    temp->next = Todel->next;
    cout << "deleted node is: " << Todel->data << endl;
    delete Todel;

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
    node* head = NULL;
    cout << "before delete node" << endl;
    insertNode(head, 50);
    insertNode(head, 40);
    insertNode(head, 30);
    insertNode(head, 20);
    insertNode(head, 10);
    display(head);
    cout << "delete after specific position node" << endl;
    afterSpecificPos(head, 30);
    cout << "deleteb before specific position " << endl;
    beforeSpecificPos(head,30);
    display(head);
    
    return 0;
}
