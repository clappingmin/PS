#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 100 + 1

using namespace std;

int m, n, k;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int i, int j)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    visited[i][j] = true;
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

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (map[nx][ny] == 1 || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v;
    int res = 0;
    cin >> m >> n >> k;

    while (k--)
    {
        int sx, sy, ex, ey;

        cin >> sy >> sx >> ey >> ex;

        for (int i = sx; i < ex; i++)
            for (int j = sy; j < ey; j++)
                map[i][j] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!map[i][j] && !visited[i][j])
            {
                int temp = bfs(i, j);
                v.push_back(temp);
                res++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << res << '\n';

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}