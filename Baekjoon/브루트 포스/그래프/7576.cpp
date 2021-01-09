#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int tomato[MAX][MAX];
queue<pair<int, int>> q;
int m, n;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int direction = 0; direction < 4; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (tomato[nx][ny] || tomato[nx][ny] == -1)
                continue;

            tomato[nx][ny] = tomato[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int day = 0;
    bool flag = true;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push(make_pair(i,j));
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
            if (day < tomato[i][j])
                day = tomato[i][j];
        }

    }
    if (flag)
        cout << day - 1 << '\n';

    return 0;
}