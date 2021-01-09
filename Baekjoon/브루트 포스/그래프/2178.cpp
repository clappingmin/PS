#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int map[100][100];
int dist[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    dist[i][j] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n && y == m)
        { //도착했으면
            break;
        }

        for (int direction = 0; direction < 4; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] || !map[nx][ny])
                continue;

            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            map[i][j] = s[j] - '0';
    }

    bfs(0, 0);

    cout << dist[n - 1][m - 1];

    return 0;
}