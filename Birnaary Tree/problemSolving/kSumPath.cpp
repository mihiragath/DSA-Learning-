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

void solve(node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }

    path.pop_back();
}

int sumK(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

node *buildTree()
{
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *newnode = new node(data);
    cout << "Enter left child of " << data << endl;
    newnode->left = buildTree();
    cout << "Enter right child of " << data << endl;
    newnode->right = buildTree();

    return newnode;
}

int main()
{
    node *root = NULL;
    int k;

    cout << "Build the tree:" << endl;
    root = buildTree();

    cout << "Enter the value of k: ";
    cin >> k;

    int result = sumK(root, k);
    cout << "Number of paths with sum " << k << " is: " << result << endl;

    return 0;
}
