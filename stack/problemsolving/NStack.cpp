#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;       // Array to store elements
vector<int> top;       // Array to store the top indices of each stack
vector<int> nextIndex; // Array to store the next free index or next element in the stack
int freespot;          // Index of the next free spot in the array

void initializeNStack(int numStacks, int stackSize)
{
    arr.resize(stackSize);
    top.resize(numStacks, -1);
    nextIndex.resize(stackSize);

    // Initialize nextIndex array
    for (int i = 0; i < stackSize - 1; i++)
    {
        nextIndex[i] = i + 1;
    }
    nextIndex[stackSize - 1] = -1; // Last index points to -1

    freespot = 0; // Initialize freespot
}

bool push(int x, int m)
{
    if (freespot == -1)
    {
        return false; // Stack overflow
    }

    int index = freespot;
    freespot = nextIndex[index];
    arr[index] = x;
    nextIndex[index] = top[m - 1];
    top[m - 1] = index;

    return true;
}

int pop(int m)
{
    if (top[m - 1] == -1)
    {
        return -1; // Stack underflow
    }

    int index = top[m - 1];
    top[m - 1] = nextIndex[index];
    nextIndex[index] = freespot;
    freespot = index;

    return arr[index];
}

int main()
{
    int numStacks = 3;  // Number of stacks
    int stackSize = 10; // Size of the array

    // Initialize the NStack
    initializeNStack(numStacks, stackSize);

    // Push elements into stacks
    push(10, 1);
    push(20, 1);
    push(30, 2);
    push(40, 3);
    push(50, 2);

    // Pop elements from stacks
    cout << "Popped from stack 1: " << pop(1) << endl; // 20
    cout << "Popped from stack 2: " << pop(2) << endl; // 30
    cout << "Popped from stack 3: " << pop(3) << endl; // 40
    cout << "Popped from stack 1: " << pop(1) << endl; // 10

    return 0;
}
