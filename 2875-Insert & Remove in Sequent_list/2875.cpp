#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int tmp;
    for (int i=0; i<n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    int m;
    cin >> m;
    char op;
    for (int i=0; i<m; i++)
    {
        cin >> op;
        if (op == 'I')
        {
            int pos,data;
            cin >> pos >> data;
            arr.insert(arr.begin()+pos-1, data);
        }
        if (op == 'D')
        {
            int pos;
            cin >> pos;
            arr.erase(arr.begin()+pos-1);
        }
    }
    if (arr.size() == 0) cout << "EMPTY";
    else for (int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}