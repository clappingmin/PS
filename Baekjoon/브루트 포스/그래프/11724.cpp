#include <iostream>
#include <queue>
#define MAX 1000 + 1

using namespace std;

int n, m;
int map[MAX][MAX];
queue<int> q;
bool visited[MAX];

void dfs(int v)
{
    visited[v] = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false && map[v][i])
            dfs(i);
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
        for (int i = 1; i <= n; i++)
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

    int cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
