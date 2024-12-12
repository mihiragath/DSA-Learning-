#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;

    // Process first window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Push answer for the first window
    if (!dq.empty())
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // Process remaining windows
    for (int i = k; i < n; i++)
    {
        // Remove elements out of the current window
        if (!dq.empty() && (i - dq.front()) >= k)
        {
            dq.pop_front();
        }

        // Add the current element if it's negative
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        // Push the first negative integer in the current window
        if (!dq.empty())
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        long long int n, k;
        cout << "Enter the size of the array: ";
        cin >> n;

        long long int arr[n];
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Enter the window size: ";
        cin >> k;

        vector<long long> result = printFirstNegativeInteger(arr, n, k);
        cout << "Output: ";
        for (auto it : result)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
