#include <iostream>
#include <queue>
#define MAX 500 + 1

using namespace std;

int visited[MAX];
int map[MAX][MAX];
queue<int> q;
int n, m, res = 0;

void bfs()
{
    visited[1]++;
    q.push(1);

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && map[tmp][i])
            {
                visited[i] = visited[tmp] + 1;

                if (visited[i] > 3)
                    continue;
                q.push(i);
                res++;

            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        map[x][y] = 1;
        map[y][x] = 1;
    }

    bfs();
    cout << res << '\n';

    return 0;
}