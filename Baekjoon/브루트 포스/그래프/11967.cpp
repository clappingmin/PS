#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

int n, m;
vector<pair<int, int>> v[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j)
{
    int cnt = 1;
    check[i][j] = true;
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
            int ny = y + dx[dir];

            for (int i = 0; i < v[x][y].size(); i++)
            {
                int ix = v[x][y][i].first;
                int iy = v[x][y][i].second;

                if (check[ix][iy])
                    continue;

                if (nx == ix && ny == iy && check[nx][ny] == false)
                {
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int res = 1;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;

        cin >> x >> y >> a >> b;

        v[x][y].push_back(make_pair(a, b));
    }

    for (int i = 0; i < v[1][1].size(); i++)
    {
        int x = v[1][1][i].first;
        int y = v[1][1][i].second;

        res += bfs(x, y);
    }

    cout << res << '\n';

    return 0;
}