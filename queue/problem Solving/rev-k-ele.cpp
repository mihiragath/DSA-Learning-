#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> revKElement(queue<int> q, stack<int> s, int k)
{
    for (int i = 0; i < k; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int k = 3;
    queue<int> q;
    stack<int> s;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Original Queue: ";
    printQueue(q);

    q = revKElement(q, s, k);

    cout << "Modified Queue: ";
    printQueue(q);

    return 0;
}
