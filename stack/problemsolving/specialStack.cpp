#include <stack>
#include <limits.h>
#include <iostream>
using namespace std;

// Global variables to store the stack and the minimum value
stack<int> s;       // Standard stack to store elements
int mini = INT_MAX; // Variable to store the minimum element in the stack

// Function to push an element into the stack
void push(int data)
{
    // If the stack is empty, initialize it with the first element
    if (s.empty())
    {
        s.push(data);
        mini = data; // Set the first element as the minimum
    }
    else
    {
        // If the new element is less than the current minimum
        if (data < mini)
        {
            // Push a modified value into the stack to store the relationship
            s.push(2 * data - mini);
            mini = data; // Update the minimum value
        }
        else
        {
            // If the new element is not less than the current minimum, push it directly
            s.push(data);
        }
    }
}

// Function to pop the top element from the stack
int pop()
{
    // If the stack is empty, return -1
    if (s.empty())
    {
        return -1;
    }

    int curr = s.top(); // Get the top element
    s.pop();            // Remove the top element

    if (curr > mini)
    {
        // If the current value is greater than or equal to the minimum, return it
        return curr;
    }
    else
    {
        // If the current value is less than the minimum, it is a special encoded value
        int prevMin = mini;     // Save the current minimum to return
        mini = 2 * mini - curr; // Decode the previous minimum
        return prevMin;         // Return the actual popped value
    }
}

// Function to get the top element of the stack
int top()
{
    // If the stack is empty, return -1
    if (s.empty())
    {
        return -1;
    }

    int curr = s.top(); // Get the top element

    if (curr < mini)
    {
        // If the top value is less than the minimum, return the minimum
        return mini;
    }
    else
    {
        // Otherwise, return the top value as is
        return curr;
    }
}

// Function to check if the stack is empty
bool isEmpty()
{
    return s.empty(); // Return true if the stack is empty, false otherwise
}

// Function to get the minimum element in the stack
int getMin()
{
    // If the stack is empty, return -1
    if (s.empty())
    {
        return -1;
    }
    // Otherwise, return the minimum value
    return mini;
}

// Main function to demonstrate the use of the special stack
int main()
{
    push(5);  // Push 5 into the stack
    push(2);  // Push 2 into the stack
    push(10); // Push 10 into the stack
    push(1);  // Push 1 into the stack

    // Output the minimum value in the stack
    cout << "Minimum: " << getMin() << endl; // Output: 1

    // Output the top value in the stack
    cout << "Top: " << top() << endl; // Output: 1

    // Pop the top value from the stack and output it
    cout << "Pop: " << pop() << endl; // Output: 1

    // Output the minimum value in the stack after the pop operation
    cout << "Minimum: " << getMin() << endl; // Output: 2

    // Pop the top value from the stack and output it
    cout << "Pop: " << pop() << endl; // Output: 10

    // Check if the stack is empty and output the result
    cout << "Is Empty: " << (isEmpty() ? "Yes" : "No") << endl; // Output: No

    return 0;
}
