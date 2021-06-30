#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

char cmd[] = {'D', 'S', 'L', 'R'};
bool check[10001];

int calc(int num, int d)
{
    if (d == 0)
        return 2 * num % 10000;

    else if (d == 1)
    {
        if (num == 0)
            return 9999;
        else
            return num - 1;
    }
    else if (d == 2)
    {
        int d1 = num / 1000;
        int d2 = num / 100 % 10;
        int d3 = num / 10 % 10;
        int d4 = num % 10;

        return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
    }
    else if (d == 3)
    {
        int d1 = num / 1000;
        int d2 = num / 100 % 10;
        int d3 = num / 10 % 10;
        int d4 = num % 10;

        return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
    }
}

string bfs(int a, int b)
{
    queue<pair<int, string>> q;
    check[a] = true;
    q.push({a, ""});

    while (!q.empty())
    {
        int x = q.front().first;
        string s = q.front().second;
        q.pop();

        if (x == b)
            return s;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = calc(x, dir);

            if (nx < 0 || nx >= 10000)
                continue;

            if (check[nx] == true)
                continue;

            check[nx] = true;
            q.push({nx, s + cmd[dir]});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        memset(check, false, sizeof(check));

        cout << bfs(a, b) << '\n';
    }

    return 0;
}