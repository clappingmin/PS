#include <iostream>
#include <queue>
#define MAX 1000000000

using namespace std;

long long a, b;

void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, 1));

    while (!q.empty())
    {
        long long num = q.front().first;
        long long cnt = q.front().second;
        q.pop();

        if (num == b)
        {
            cout << cnt << '\n';
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            long long nx;

            if (i == 0)
                nx = num * 2;
            else
                nx = num * 10 + 1;

            if (nx <= 0 || nx > MAX)
                continue;

            q.push(make_pair(nx, cnt + 1));
        }
    }
    cout << -1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    bfs();

    return 0;
}