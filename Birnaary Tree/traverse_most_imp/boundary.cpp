#include <iostream>
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

// Traverse leaf nodes
void traverseLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// Traverse left boundary (excluding leaf nodes)
void traverseLeft(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

// Traverse right boundary (excluding leaf nodes)
void traverseRight(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data); // Add root node

    // Traverse left boundary
    traverseLeft(root->left, ans);

    // Traverse leaf nodes
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // Traverse right boundary
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    node *root = NULL;
    cout << "Build the tree:" << endl;
    root = buildTree();

    vector<int> ans = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
