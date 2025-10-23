#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N,Q;
    cin >> N >> Q;
    int sum = 0, count = 0;
    queue<int> q;
    int temperature;
    for (int i = 0; i < Q; i++)
    {
        cin >> temperature;
        q.push(temperature);
        sum += temperature;
        count++;
        if (count > N)
        {
            sum -= q.front();
            q.pop();
            count--;
        }
        cout << sum / count << endl;
    }
}
