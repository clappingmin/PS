#include <iostream>
#include <algorithm>

using namespace std;

int res = 1;
int r, c;
char map[20][20];
bool check[26];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void move(int x, int y, int cnt)
{
    res = max(res, cnt);

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;

        int temp = map[nx][ny] - 'A';
        if (check[temp])
            continue;

        check[temp] = true;
        move(nx, ny, cnt + 1);
        check[temp] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    int temp = map[0][0] - 'A';
    check[temp] = true;

    move(0, 0, 1);

    cout << res << '\n';

    return 0;
}