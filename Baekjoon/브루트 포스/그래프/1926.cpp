#include <iostream>
#include <queue>
#define MAX 500
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

int bfs(int i, int j)
{
    int s = 1;
    queue<pair<int, int>> q;
    visited[i][j] = true;

    q.push(make_pair(i, j));

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
            if (visited[nx][ny] || !board[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            s++;
        }
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0, size = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] && !visited[i][j])
            {
                int tmp = bfs(i, j);
                cnt++;

                if (tmp > size)
                    size = tmp;
            }
        }
    }

    cout << cnt << '\n'<< size;

    return 0;
}