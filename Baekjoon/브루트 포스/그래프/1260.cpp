#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001

using namespace std;

int n, m, start;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;

void dfs(int v)
{
    cout << v << ' ';
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
        v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false && map[v][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }

    dfs(start);
    cout << "\n";
    memset(visited,false,sizeof(visited));

    bfs(start);

    return 0;
}