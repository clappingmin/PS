#include <iostream>

using namespace std;

int N, M;
char map[50][50];
bool visited[50][50];
int dist[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool DFS(int x, int y, int cnt)
{
    if (visited[x][y])
    {
        if (cnt - dist[x][y] >= 4)
            return true;
        else
            return false;
    }
    visited[x][y] = true;
    dist[x][y] = cnt;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;

        if (map[nx][ny] != map[x][y])
            continue;

        if (DFS(nx, ny, cnt + 1))
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    string res = "No";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                if (DFS(i, j, 0))
                    res = "Yes";
            }
        }
    }

    cout << res << "\n";

    return 0;
}