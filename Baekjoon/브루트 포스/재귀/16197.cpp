#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
char map[20][20];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int res = INT_MAX;

bool fall_coin(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) //동전이 떨어짐
        return true;

    return false;
}

void move_coin(int x1, int y1, int x2, int y2, int cnt, int dir)
{
    if (res < cnt)
        return;

    if (cnt > 10)
    {
        res = min(res, cnt);
        return;
    }
    int nx1 = x1 + dx[dir];
    int ny1 = y1 + dy[dir];
    int nx2 = x2 + dx[dir];
    int ny2 = y2 + dy[dir];

    if (fall_coin(nx1, ny1) == true && fall_coin(nx2, ny2) == true) //동전 두개가 떨어질 경우
        return;

    else if (fall_coin(nx1, ny1) == false && fall_coin(nx2, ny2) == true)
    {
        res = min(cnt, res);
        return;
    }
    else if (fall_coin(nx1, ny1) == true && fall_coin(nx2, ny2) == false)
    {
        res = min(cnt, res);
        return;
    }

    if (map[nx1][ny1] == '#')
    {
        nx1 = x1;
        ny1 = y1;
    }
    if (map[nx2][ny2] == '#')
    {
        nx2 = x2;
        ny2 = y2;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        move_coin(nx1, ny1, nx2, ny2, cnt + 1, dir);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int x1 = -1, y1, x2, y2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'o')
            {
                if (x1 == -1)
                {
                    x1 = i;
                    y1 = j;
                }
                else
                {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }

    for (int dir = 0; dir < 4; dir++)
    {
        move_coin(x1, y1, x2, y2, 1, dir);
    }

    if (res > 10)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}