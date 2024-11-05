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

node* reverse(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAns(node* &head, node* &tail, int val) {
    node* temp = new node(val);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;    
    }
}

node* add(node* &first, node* &second) {
    int carry = 0;
    node* ansHead = NULL;
    node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0) {
        int val1 = (first != NULL) ? first->data : 0;
        int val2 = (second != NULL) ? second->data : 0;

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        insertAns(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL) first = first->next;
        if (second != NULL) second = second->next;
    }
    return ansHead;
}

node* sum(node* &head, node* &head1) {
    node* first = reverse(head);
    node* second = reverse(head1);

    node* temp = add(first, second);
    node* ans = reverse(temp);

    return ans;
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
    node* node1 = new node(5);
    node* head = node1;
    insertAtstart(head, 4);
    disply(head);

    cout << "list 2:" << endl;
    node* node2 = new node(5);
    node* head1 = node2;
    insertAtstart(head1, 4);
    insertAtstart(head1, 3);
    disply(head1);

    node* result = sum(head, head1);
    cout << "Sum of lists:" << endl;
    disply(result);

    return 0;
}
