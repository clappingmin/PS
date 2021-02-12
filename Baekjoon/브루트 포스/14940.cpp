#include <iostream>
#include <queue>

using namespace std;

int n, m, sx, sy;
int map[1000][1000];
bool check[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j)
{
    map[i][j] = 0;
    check[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});

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

            if (map[nx][ny] == 0 || check[nx][ny] == true)
                continue;

            check[nx][ny] = true;
            map[nx][ny] = map[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void is_check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && !check[i][j])
                map[i][j] = -1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 2)
            {
                sx = i;
                sy = j;
            }
        }
    }

    bfs(sx, sy);

    is_check();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}