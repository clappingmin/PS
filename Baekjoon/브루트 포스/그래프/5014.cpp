#include <iostream>
#include <queue>
#define MAX 1000000

using namespace std;

int f, s, g, u, d;
int map[MAX + 1];
bool check[MAX + 1];

int bfs(int s)
{
    check[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == g)
            return map[now];

        for (int i = 0; i < 2; i++)
        {
            int next;
            if (i == 0)
                next = now + u;
            else
                next = now - d;

            if (next <= 0 || next > f)
                continue;
            if (check[next])
                continue;

            map[next] = map[now] + 1;
            check[next] = true;
            q.push(next);
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    int res = bfs(s);
    if (s == g)
        cout << 0 << '\n'; //현재 층과 스타트링크 층이 같을 때
    else if (res)
        cout << res << '\n';
    else
        cout << "use the stairs" << '\n';

    return 0;
}