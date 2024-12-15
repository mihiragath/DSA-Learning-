#include <iostream>
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

int sumOFLongestPath(node *root, int sum, int &maxSum, int length, int &maxLength)
{
    if (root == NULL)
    {
        if (length > maxLength)
        {
            maxLength = length;
            maxSum = sum;
        }
        if (length == maxLength)
        {
            maxSum = max(sum, maxSum);
        }
        return 0;
    }

    sum += root->data;

    sumOFLongestPath(root->left, sum, maxSum, length + 1, maxLength);
    sumOFLongestPath(root->right, sum, maxSum, length + 1, maxLength);
    return maxSum;
}

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

int main()
{
    node *root = buildTree();
    int sum = 0;
    int maxSum = 0;
    int length = 0;
    int maxLength = 0;

    sumOFLongestPath(root, sum, maxSum, length, maxLength);

    cout << "Maximum Sum of Longest Path: " << maxSum << endl;
    return 0;
}
