#include <iostream>
#include <map>
#include <vector>
#include <queue>
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

vector<int> verticalOrder(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        nodes[horizontalDistance][level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance - 1, level + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
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

    vector<int> result = verticalOrder(root);

    cout << "Vertical Order Traversal: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
