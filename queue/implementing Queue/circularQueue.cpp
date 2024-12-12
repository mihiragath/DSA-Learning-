#include <iostream>
using namespace std;

struct CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;
};

CircularQueue createQueue(int n)
{
    CircularQueue q;
    q.size = n;
    q.arr = new int[q.size];
    q.front = q.rear = -1;
    return q;
}

bool enqueue(CircularQueue &q, int value)
{
    if ((q.front == 0 && q.rear == q.size - 1) || (q.rear == (q.front - 1) % (q.size - 1)))
    {
        return false;
    }
    else if (q.front == -1)
    {
        q.front = q.rear = 0;
    }
    else if (q.rear == q.size - 1 && q.front != 0)
    {
        q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.arr[q.rear] = value;
    return true;
}

int dequeue(CircularQueue &q)
{
    if (q.front == -1)
    {
        return -1;
    }
    int ans = q.arr[q.front];
    q.arr[q.front] = -1;
    if (q.front == q.rear)
    {
        q.front = q.rear = -1;
    }
    else if (q.front == q.size - 1)
    {
        q.front = 0;
    }
    else
    {
        q.front++;
    }
    return ans;
}

int main()
{
    CircularQueue q = createQueue(5);

    cout << "Enqueue 10: " << (enqueue(q, 10) ? "Success" : "Failed") << endl;
    cout << "Enqueue 20: " << (enqueue(q, 20) ? "Success" : "Failed") << endl;
    cout << "Enqueue 30: " << (enqueue(q, 30) ? "Success" : "Failed") << endl;
    cout << "Enqueue 40: " << (enqueue(q, 40) ? "Success" : "Failed") << endl;
    cout << "Enqueue 50: " << (enqueue(q, 50) ? "Success" : "Failed") << endl;

    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;

    cout << "Enqueue 60: " << (enqueue(q, 60) ? "Success" : "Failed") << endl;
    cout << "Enqueue 70: " << (enqueue(q, 70) ? "Success" : "Failed") << endl;

    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;

    return 0;
}
