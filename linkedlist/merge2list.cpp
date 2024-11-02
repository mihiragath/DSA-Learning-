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

node* mergeList(node* &head, node* &head1) {
    if (head == NULL) return head1;
    if (head1 == NULL) return head;

    node* onecurrent = NULL;
    node* twocurrent = NULL;

    if (head->data <= head1->data) {
        onecurrent = head;
        head = head->next;
    } else {
        onecurrent = head1;
        head1 = head1->next;
    }
    twocurrent = onecurrent;

    while (head != NULL && head1 != NULL) {
        if (head->data <= head1->data) {
            twocurrent->next = head;
            head = head->next;
        } else {
            twocurrent->next = head1;
            head1 = head1->next;
        }
        twocurrent = twocurrent->next;
    }

    if (head != NULL) {
        twocurrent->next = head;
    } else {
        twocurrent->next = head1;
    }

    return onecurrent;
}

void disply(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    cout << "list 1:" << endl;
    node* node1 = new node(70);
    node* head = node1;
    insertAtstart(head, 50);
    insertAtstart(head, 30);
    insertAtstart(head, 10);
    disply(head);

    cout << "list 2:" << endl;
    node* node2 = new node(60);
    node* head1 = node2;
    insertAtstart(head1, 40);
    insertAtstart(head1, 20);
    disply(head1);

    cout << "merged list:" << endl;
    node* mergedHead = mergeList(head, head1);
    disply(mergedHead);

    return 0;
}
