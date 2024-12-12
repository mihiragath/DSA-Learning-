#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void nonRepeatingChar(char arr[], int size)
{
    unordered_map<char, int> count;
    queue<char> q;

    for (int i = 0; i < size; i++)
    {
        char ch = arr[i];
        q.push(ch);
        count[ch]++;

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
        {
            cout << "# ";
        }
    }
    cout << endl;
}

void printArray(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    char arr[4] = {'a', 'a', 'b', 'c'};

    cout << "Original array: ";
    printArray(arr, 4);

    cout << "Non-repeating characters: ";
    nonRepeatingChar(arr, 4);

    return 0;
}
