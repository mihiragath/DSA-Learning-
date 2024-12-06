#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<int> s;
    int arr[5] = {2, 1, 4, 5, 3};
    int n = 5;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int current = arr[i];
        while (!s.empty() && s.top() >= current)
        {
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(current);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Next smaller element for " << arr[i] << " is " << ans[i] << endl;
    }

    return 0;
}
