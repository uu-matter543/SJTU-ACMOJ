#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    stack<int> index;
    int n;
    cin >> n;
    int result[n];
    int h;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (s.empty() || h <= s.top())
        {
            s.push(h);
            index.push(i);
        }
        else
        {
            while (!s.empty() && h > s.top())
            {
                result[index.top()] = i+1;
                s.pop();
                index.pop();
            }
            s.push(h);
            index.push(i);
        }
    }
    while (!s.empty())
    {
        result[index.top()] = 0;
        s.pop();
        index.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
