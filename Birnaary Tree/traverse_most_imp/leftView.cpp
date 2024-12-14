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
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *newNode = new node(data);

    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

void solve(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

vector<int> leftView(node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    node *root = NULL;

    root = buildTree();
    vector<int> result = leftView(root);

    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}
