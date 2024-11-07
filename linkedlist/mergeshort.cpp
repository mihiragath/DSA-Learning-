#include <iostream> 

using namespace std; 

class node{
    public: 
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtfirst(node* &head, int data){
    node* newNode;

    if(head == NULL){
        cout << "empty" << endl;
    }
    newNode->data = data;
    newNode->next = head;
    newNode = head;

}

void disply(node* head){
    node* temp = head;

    if(temp != NULL){
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
    }
    cout << endl;
    }
}

int main() {
    node* node1 = new node(10);

    node* head = node1;
    insertAtfirst(head,20);
    return 0;
}