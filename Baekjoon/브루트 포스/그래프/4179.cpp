#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char maze[MAX][MAX];
int fire[MAX][MAX];
int visited[MAX][MAX];
int r, c;
queue<pair<int, int>> q;

void bfs()
{
    int x = q.front().first;
    int y = q.front().second;

    fire[x][y] = 0;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int direction = 0; direction < 4; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (maze[nx][ny] == '#' || fire[nx][ny] || maze[nx][ny] == 'F')
                continue;

            fire[nx][ny] = fire[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}
void escape(int i, int j)
{
    visited[i][j] = 0;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == r - 1 || y == 0 || y == c - 1)
        {
            cout << visited[x][y] + 1 << '\n';
            return;
        }

        for (int direction = 0; direction < 4; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (maze[nx][ny] == '#' || visited[x][y] + 1 >= fire[nx][ny] || visited[nx][ny])
                continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int jx, jy;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'F')
            {
                q.push(make_pair(i, j));
            }
            else if (maze[i][j] == 'J')
            {
                jx = i;
                jy = j;
            }
        }
    }
    if (!q.empty())
        bfs();
    else
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
                fire[i][j] = 1000001;
        }
    escape(jx, jy);

    return 0;
}