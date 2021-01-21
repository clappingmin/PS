#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define MAX 100

using namespace std;

int m, n; //가로크기, 세로 크기
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    visited[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (map[nx][ny] == 1)
            {
                if (visited[nx][ny] > visited[x][y] + 1)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
            else if (map[nx][ny] == 0)
            {
                if (visited[nx][ny] > visited[x][y])
                {
                    visited[nx][ny] = visited[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    string s;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
            visited[i][j] = 987654321;
        }
    }

    bfs();
    cout << visited[n - 1][m - 1] << '\n';

    return 0;
}