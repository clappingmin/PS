#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX];
bool check[MAX][MAX];
int n, s = 100, e = 1;

void bfs(int i, int j, int boundary)
{
    queue<pair<int, int>> q;
    check[i][j] = true;
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

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (map[nx][ny] <= boundary || check[nx][ny])
                continue;
            check[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int res = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] < s)
                s = map[i][j];
            if (map[i][j] > e)
                e = map[i][j];
        }
    }

    for (int i = s; i <= e; i++)
    {
        memset(check, false, sizeof(check));
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (map[j][k] > i && check[j][k] == false)
                {
                    bfs(j, k, i);
                    temp++;
                }
            }
        }

        if (res < temp)
            res = temp;
    }
    if (res == 0)
        cout << 1;
    else
        cout << res;

    return 0;
}