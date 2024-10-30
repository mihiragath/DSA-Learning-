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


void insertAtlast(node* &head , int data){
    node* New = new node(data);
    node* temp = head;
    while(temp->next = NULL){
        temp = temp->next;
    }
    temp->next = New;
    New->next=NULL;

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


    insertAtlast(head,5);
    disply(head);

    return 0;
}
