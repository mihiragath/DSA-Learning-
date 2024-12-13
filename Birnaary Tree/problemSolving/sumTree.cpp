#include <iostream>
#include <utility>
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

pair<bool, int> isSum(node *root)
{
    if (root == NULL)
    {
        return make_pair(true, 0);
    }

    if (root->left == NULL && root->right == NULL)
    {
        return make_pair(true, root->data);
    }

    pair<bool, int> leftAns = isSum(root->left);
    pair<bool, int> rightAns = isSum(root->right);

    bool isLeftSum = leftAns.first;
    bool isRightSum = rightAns.first;
    bool condition = (root->data == leftAns.second + rightAns.second);

    pair<bool, int> ans;
    if (isLeftSum && isRightSum && condition)
    {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

int main()
{
    node *root = NULL;
    cout << "Build the tree:" << endl;
    root = buildTree();

    if (isSum(root).first)
    {
        cout << "The tree satisfies the sum property." << endl;
    }
    else
    {
        cout << "The tree does not satisfy the sum property." << endl;
    }

    return 0;
}
