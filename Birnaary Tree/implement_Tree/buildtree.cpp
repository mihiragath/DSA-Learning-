#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree()
{
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *newNode = new node(data);

    cout << "Enter left child of " << data << endl;
    newNode->left = buildTree();

    cout << "Enter right child of " << data << endl;
    newNode->right = buildTree();

    return newNode;
}

int main()
{
    node *root = NULL;

    cout << "Build the tree:" << endl;
    root = buildTree();

    return 0;
}
