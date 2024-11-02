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

    node* getMid(node* head) {
        node* slow = head;
        node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
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


    bool isPalindrome(node* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        node* middle = getMid(head);
        node* temp = middle->next;
        middle->next = reverse(temp);

        node* head1 = head;
        node* head2 = middle->next;

        while (head2 != NULL) {
            if (head2->data != head1->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }


void insertAtStart(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
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
    node* head = NULL;

    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 20);
    insertAtStart(head, 10);

    display(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
