#include <iostream>
#include <map>
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

void createMapping(int in[], map<int, int> &nodeIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeIndex[in[i]] = i;
    }
}

node *buildTree(int in[], int post[], int &postIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeIndex)
{
    if (postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = post[postIndex--];
    node *temp = new node(element);

    int position = nodeIndex[element];
    temp->right = buildTree(in, post, postIndex, position + 1, inOrderEnd, n, nodeIndex);
    temp->left = buildTree(in, post, postIndex, inOrderStart, position - 1, n, nodeIndex);

    return temp;
}

void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    int in[6] = {3, 1, 4, 0, 5, 2};
    int post[6] = {3, 4, 1, 5, 2, 0};
    int n = 6;

    map<int, int> nodeIndex;
    createMapping(in, nodeIndex, n);

    int postIndex = n - 1;
    node *root = buildTree(in, post, postIndex, 0, n - 1, n, nodeIndex);

    cout << "Preorder Traversal of the constructed tree: ";
    preOrderTraversal(root);

    return 0;
}
