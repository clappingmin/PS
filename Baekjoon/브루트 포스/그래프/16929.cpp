#include <iostream>
#include <string>
#include <cstring>
#define MAX 50

using namespace std;

int n, m;
char map[MAX][MAX];
bool check[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool dfs(int x, int y, int cnt, char color)
{
    if (check[x][y]) //이미 방문했던 노드
    {
        if (cnt - dist[x][y] >= 4)
            return true;

        else
            return false;
    }

    check[x][y] = true;
    dist[x][y] = cnt;

    for (int direction = 0; direction < 4; direction++)
    {
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (map[nx][ny] == color)
        {
            if (dfs(nx, ny, cnt + 1, color))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> n >> m;

    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j])
                continue;

            memset(dist, 0, sizeof(dist));
            bool ok = dfs(i, j, 1, map[i][j]);

            if (ok)
            {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}