#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int map[500][500];
bool check[500][500];
vector<pair<int, int>> select_v;
int res = INT_MIN;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt)
{
    if (cnt == 4)
    {
        int temp = 0;
        for (int i = 0; i < 4; i++)
        {
            int sx = select_v[i].first;
            int sy = select_v[i].second;

            temp += map[sx][sy];
        }
        res = max(res, temp);

        return;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        if (check[nx][ny])
            continue;

        check[nx][ny] = true;
        select_v.push_back({nx, ny});

        dfs(x, y, cnt + 1); // ㅜ 모양을 위해서
        dfs(nx, ny, cnt + 1);

        select_v.pop_back();
        check[nx][ny] = false;
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
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!check[i][j])
            {
                check[i][j] = true;
                select_v.push_back({i,j});
                dfs(i, j, 1);
                select_v.pop_back();
            }
        }
    }

    cout << res << '\n';
    return 0;
}