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

node* floydDetectLoop(node* head) {
    if (head == NULL)
        return NULL;

    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Loop detected
        }
    }

    return NULL; // No loop
}

node* getStatNode(node* &head){
    if(head == NULL){
        cout << "empty" << endl;
        return NULL;
    }

    node* start = floydDetectLoop(head);
    node* slow = head;

    while(slow !=  start){
        slow = slow->next;
        start = start->next;
    }

    return slow;

}

node* removeLoop(node* &head){
    if(head == NULL){
        return NULL;
    }

    node* startingnode = getStatNode(head);
    node* temp = startingnode;

    while(temp->next != startingnode ){
        temp = temp->next;
    }

    temp->next = NULL;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;

    insertAtstart(head, 20);
    insertAtstart(head, 30);
    insertAtstart(head, 40);
    insertAtstart(head, 50);
    
    // Create a loop for testing
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head->next; // Create a loop

    node* loopNode = floydDetectLoop(head);
    if (loopNode != NULL) {
        cout << "\nLoop detected in the linked list." << endl;
    } else {
        cout << "\nNo loop detected in the linked list." << endl;
    }
    cout << "Starting node of the loop is:" << getStatNode(head)->data << endl;

    node* remove = removeLoop(head);
    cout << "loop end with node is which one node used to remove the node:" << remove->data << endl;
    return 0;
}
