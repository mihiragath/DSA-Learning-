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
// int height(node *root)
// {
//     if (root == NULL)
//     {
//         cout << "tree is empty";
//     }

//     int left = height(root->left);
//     int right = height(root->right);
//     int ans = max(left, right) + 1;

//     return ans;
// }

// int diameter(node *root)
// {
//     if (root == NULL)
//     {
//         cout << "tree is empty";
//     }

//     int option1 = diameter(root->left);
//     int option2 = diameter(root->right);
//     int option3 = height(root->left) + height(root->right) + 1;

//     int ans = max(option1, max(option2, option3));
//     return ans;
// }

pair<int, int> diameterfast(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterfast(root->left);
    pair<int, int> right = diameterfast(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(option1, max(option2, option3)); // Maximum diameter
    ans.second = max(left.second, right.second) + 1; // Height of the current node
    return ans;
}

int diameter(node *root)
{
    return diameterfast(root).first; // Get the diameter from the pair's first value
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

    cout << "Maximum diameter of the tree is: " << diameter(root) << endl;

    return 0;
}