#include <iostream>
#include <queue>
#define MAX 20000 + 1

using namespace std;

int map[MAX][MAX];
queue<int> q;
int visited[MAX];
int n, m;

void bfs(int v)
{
    visited[v] = 1;
    q.push(v);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for (int i = 2; i <= n; i++)
        {
            if (visited[i] == 0 && map[tmp][i])
            {
                visited[i] = visited[tmp] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 0, res = 0, cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        map[x][y] = 1;
        map[y][x] = 1;
    }

    bfs(1);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] > res)
        {
            res = visited[i];
            num = i;
        }
        else if (visited[i] == res)
            cnt++;
    }

    cout << num << ' ' << res-1 << ' ' << cnt << '\n';

    return 0;
}