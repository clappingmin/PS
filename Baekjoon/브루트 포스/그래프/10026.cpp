#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100

using namespace std;

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[MAX][MAX];
bool visited[MAX][MAX];

void bfs1(int i, int j) //적록색약이 아닌 사람
{
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 | ny >= n)
                continue;
            if (map[x][y] != map[nx][ny])
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

void bfs2(int i, int j) //적록색약이 아닌 사람
{
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 | ny >= n)
                continue;
            if (visited[nx][ny])
                continue;

            if (map[x][y] == 'B' && map[x][y] == map[nx][ny])
            {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
            else if (map[x][y] == 'R')
            {
                if (map[nx][ny] == 'R' || map[nx][ny] == 'G')
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
            else if (map[x][y] == 'G')
            {
                if (map[nx][ny] == 'R' || map[nx][ny] == 'G')
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    int res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs1(i, j);
                res1++;
            }
        }
    }
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs2(i, j);
                res2++;
            }
        }
    }

    cout << res1 << ' ' << res2;

    return 0;
}