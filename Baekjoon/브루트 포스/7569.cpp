#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int m, n, h;
int tomato[MAX][MAX][MAX]; //z,x,y;
bool visited[MAX][MAX][MAX];
queue<pair<pair<int, int>, int>> q;
int dx[6] = {0, 0, -1, 0, 1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};
int dz[6] = {-1, 1, 0, 0, 0, 0};

void bfs()
{
    while (!q.empty())
    {
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 6; dir++)
        {
            int nz = z + dz[dir];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (tomato[nz][nx][ny] == -1 || visited[nz][nx][ny])
                continue;

            visited[nz][nx][ny] = true;
            tomato[nz][nx][ny] = tomato[z][x][y] + 1;
            q.push(make_pair(make_pair(nz, nx), ny));

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int day = 0;
    cin >> m >> n >> h; //y,x,z

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1)
                {
                    q.push(make_pair(make_pair(i, j), k));
                    visited[i][j][k] = true;
                }
            }
        }
    }

    bfs();

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomato[i][j][k] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }
                else
                {
                    if (day < tomato[i][j][k])
                        day = tomato[i][j][k];
                }
            }
        }
    }
    cout << day - 1 << '\n';

    return 0;
}