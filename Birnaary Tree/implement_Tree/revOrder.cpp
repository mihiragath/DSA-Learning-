#include <iostream>
#include <stack>
#include <queue>
#include <vector>

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

// Function for reverse level-order traversal
void revOrderTraversal(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return;
    }

    stack<vector<int>> levels; // Stack to store levels
    queue<node *> q;           // Queue for level-order traversal

    q.push(root);

    // Perform a level-order traversal
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        // Process all nodes at the current level
        for (int i = 0; i < size; ++i)
        {
            node *current = q.front();
            q.pop();
            level.push_back(current->data);

            if (current->left)
            {
                q.push(current->left);
            }
            if (current->right)
            {
                q.push(current->right);
            }
        }

        // Push the current level into the stack
        levels.push(level);
    }

    // Print levels from the stack in reverse order
    while (!levels.empty())
    {
        vector<int> level = levels.top();
        levels.pop();

        for (size_t i = 0; i < level.size(); ++i)
        {
            cout << level[i];
            if (i != level.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

int main()
{
    node *root = NULL;

    cout << "Build the tree:" << endl;
    root = buildTree();

    cout << "Reverse Level Order Traversal:" << endl;
    revOrderTraversal(root);

    return 0;
}
