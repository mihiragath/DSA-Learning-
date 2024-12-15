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

node *buildTree(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeIndex)
{
    if (preOrderIndex >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[preOrderIndex++];
    node *temp = new node(element);
    int position = nodeIndex[element];
    temp->left = buildTree(in, pre, preOrderIndex, inOrderStart, position - 1, n, nodeIndex);
    temp->right = buildTree(in, pre, preOrderIndex, position + 1, inOrderEnd, n, nodeIndex);

    return temp;
}

void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    int in[6] = {3, 1, 4, 0, 5, 2};
    int pre[6] = {0, 1, 3, 4, 2, 5};

    map<int, int> nodeIndex;
    int n = 6;

    createMapping(in, nodeIndex, n);

    int preOrderIndex = 0;
    node *root = buildTree(in, pre, preOrderIndex, 0, n - 1, n, nodeIndex);

    postOrderTraversal(root);

    return 0;
}
