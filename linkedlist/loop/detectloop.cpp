#include <iostream>
#include <map>
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

//check if linked list is in the form of loop or not
bool detectLoop(node* &head) {
    if (head == NULL) {
        return false;
    }

    map<node*, bool> visited;
    node* temp = head;

    while (temp != NULL) {
        if (visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
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
    node* head = node1;

    insertAtstart(head, 20);
    insertAtstart(head, 30);
    insertAtstart(head, 40);
    insertAtstart(head, 50);
    
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head->next;

    cout << "head:" << head->data << endl;
    cout << "end node:" << temp->data << endl;
   // disply(head);

    if (detectLoop(head)) {
        cout << "\nLoop detected in the linked list." << endl;
        cout << "loop are detected node is:" << temp->data << endl;
    } else {
        cout << "\nNo loop detected in the linked list." << endl;
    }

    return 0;
}
