#include <iostream>
using namespace std;

int size = 100001;
int *arr = new int[size];
int qfront = 0;
int rear = 0;

bool isEmpty()
{
    return qfront == rear;
}

void enqueue(int data)
{
    if (rear == size)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        arr[rear] = data;
        rear++;
    }
}

int dequeue()
{
    if (qfront == rear)
    {
        return -1;
    }
    else
    {
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }
}

int front()
{
    if (qfront == rear)
    {
        return -1;
    }
    else
    {
        return arr[qfront];
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    cout << "Front element: " << front() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Queue is empty: " << (isEmpty() ? "Yes" : "No") << endl;
    enqueue(30);
    cout << "Front element: " << front() << endl;
    cout << "Dequeued: " << dequeue() << endl;
    cout << "Queue is empty: " << (isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
