#include <iostream>
#include <stack>
#define MAX 500000 + 1

int res[MAX];
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, i = 1;
    cin >> n;
    stack<pair<int, int>> s;

    for (int i = 1; i <= n; i++)
    {
        int tower;
        cin >> tower;

        if (s.empty())
        {
            s.push(make_pair(i, tower));
            res[i] = 0;
        }
        else
        {
            while (s.top().second < tower)
            {
                s.pop();
                if (s.empty())
                {
                    res[i] = 0;
                    break;
                }
            }
            if (!s.empty())
                res[i] = s.top().first;
            s.push(make_pair(i, tower));
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';

    return 0;
}