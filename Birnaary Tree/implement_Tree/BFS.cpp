#include <iostream>
#include <queue>
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

node *buildTree(node *root)
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
    newNode->left = buildTree(newNode->left);

    cout << "Enter right child of " << data << endl;
    newNode->right = buildTree(newNode->right);

    return newNode;
}

void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;

    root = buildTree(root);

    cout << "Printing the level-order traversal output:" << endl;
    levelOrderTraversal(root);
    // data:1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return 0;
}
