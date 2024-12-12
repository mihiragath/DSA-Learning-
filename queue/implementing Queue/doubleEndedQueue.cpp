#include <iostream>
using namespace std;

struct Deque
{
    int *arr;
    int front;
    int rear;
    int size;
};

Deque createDeque(int n)
{
    Deque dq;
    dq.size = n;
    dq.arr = new int[n];
    dq.front = -1;
    dq.rear = -1;
    return dq;
}

bool isEmpty(Deque &dq)
{
    return dq.front == -1;
}

bool isFull(Deque &dq)
{
    return (dq.front == 0 && dq.rear == dq.size - 1) || (dq.front != 0 && dq.rear == (dq.front - 1) % (dq.size - 1));
}

bool pushFront(Deque &dq, int x)
{
    if (isFull(dq))
    {
        return false;
    }
    else if (isEmpty(dq))
    {
        dq.front = dq.rear = 0;
    }
    else if (dq.front == 0 && dq.rear != dq.size - 1)
    {
        dq.front = dq.size - 1;
    }
    else
    {
        dq.front--;
    }
    dq.arr[dq.front] = x;
    return true;
}

bool pushRear(Deque &dq, int x)
{
    if (isFull(dq))
    {
        return false;
    }
    else if (isEmpty(dq))
    {
        dq.front = dq.rear = 0;
    }
    else if (dq.rear == dq.size - 1 && dq.front != 0)
    {
        dq.rear = 0;
    }
    else
    {
        dq.rear++;
    }
    dq.arr[dq.rear] = x;
    return true;
}

int popFront(Deque &dq)
{
    if (isEmpty(dq))
    {
        return -1;
    }
    int ans = dq.arr[dq.front];
    dq.arr[dq.front] = -1;
    if (dq.front == dq.rear)
    {
        dq.front = dq.rear = -1;
    }
    else if (dq.front == dq.size - 1)
    {
        dq.front = 0;
    }
    else
    {
        dq.front++;
    }
    return ans;
}

int popRear(Deque &dq)
{
    if (isEmpty(dq))
    {
        return -1;
    }
    int ans = dq.arr[dq.rear];
    dq.arr[dq.rear] = -1;
    if (dq.front == dq.rear)
    {
        dq.front = dq.rear = -1;
    }
    else if (dq.rear == 0)
    {
        dq.rear = dq.size - 1;
    }
    else
    {
        dq.rear--;
    }
    return ans;
}

int getFront(Deque &dq)
{
    if (isEmpty(dq))
    {
        return -1;
    }
    return dq.arr[dq.front];
}

int getRear(Deque &dq)
{
    if (isEmpty(dq))
    {
        return -1;
    }
    return dq.arr[dq.rear];
}

int main()
{
    // Create a deque with size 5
    Deque dq = createDeque(5);

    // Test pushing elements to the front
    cout << "Push Front 10: " << (pushFront(dq, 10) ? "Success" : "Fail") << endl;
    cout << "Push Front 20: " << (pushFront(dq, 20) ? "Success" : "Fail") << endl;

    // Test pushing elements to the rear
    cout << "Push Rear 30: " << (pushRear(dq, 30) ? "Success" : "Fail") << endl;
    cout << "Push Rear 40: " << (pushRear(dq, 40) ? "Success" : "Fail") << endl;

    // Display front and rear elements
    cout << "Front Element: " << getFront(dq) << endl;
    cout << "Rear Element: " << getRear(dq) << endl;

    // Test popping elements from the front
    cout << "Pop Front: " << popFront(dq) << endl;
    cout << "Pop Front: " << popFront(dq) << endl;

    // Test popping elements from the rear
    cout << "Pop Rear: " << popRear(dq) << endl;
    cout << "Pop Rear: " << popRear(dq) << endl;

    // Test empty condition
    cout << "Is Deque Empty: " << (isEmpty(dq) ? "Yes" : "No") << endl;

    // Test pushing after emptying
    cout << "Push Rear 50: " << (pushRear(dq, 50) ? "Success" : "Fail") << endl;
    cout << "Front Element: " << getFront(dq) << endl;

    return 0;
}
