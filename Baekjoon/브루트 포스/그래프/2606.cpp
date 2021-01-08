#include <iostream>
#include <queue>
#define MAX 100 + 1

using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;
int cnt = 0;

void dfs(int v)
{
    visited[v] = true;

    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == false && map[v][i])
        {
            cnt++;
            dfs(i);
        }
    }
}

void bfs(int v)
{
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cnt++;

        for (int i = 2; i <= n; i++)
        {
            if (visited[i] == false && map[tmp][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    // dfs(1);
    // cout << cnt << '\n';

    bfs(1);
 
    cout << cnt-1 << '\n';

    return 0;
}