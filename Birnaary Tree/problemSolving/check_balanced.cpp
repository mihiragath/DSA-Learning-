#include <iostream>
#include <utility>
#include <cmath>
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
    cout << "Enter left child of " << data << ":" << endl;
    newNode->left = buildTree();
    cout << "Enter right child of " << data << ":" << endl;
    newNode->right = buildTree();
    return newNode;
}

pair<bool, int> isBalancedFast(node *root)
{
    if (root == NULL)
    {
        return make_pair(true, 0);
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool isLeftBalanced = left.first;
    bool isRightBalanced = right.first;
    bool isHeightBalanced = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    ans.first = isLeftBalanced && isRightBalanced && isHeightBalanced;

    return ans;
}

int main()
{
    node *root = NULL;
    cout << "Build the tree:" << endl;
    root = buildTree();

    if (isBalancedFast(root).first)
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
