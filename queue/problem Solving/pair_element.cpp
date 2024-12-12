#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void devideQueue(queue<int> &q, vector<int> &arr1, vector<int> &arr2)
{
    int counter = q.size();
    int no = counter / 2;

    for (int i = 0; i < no; i++)
    {
        int element = q.front();
        q.pop();
        arr1.push_back(element);
    }

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        arr2.push_back(element);
    }

    cout << "Arr1: ";
    for (int val : arr1)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Arr2: ";
    for (int val : arr2)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Pairs of Arr1 and Arr2: ";
    for (int i = 0; i < arr1.size() && i < arr2.size(); i++)
    {
        cout << "(" << arr1[i] << ", " << arr2[i] << ") ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1;
    vector<int> arr2;
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    devideQueue(q, arr1, arr2);

    return 0;
}
