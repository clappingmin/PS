#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int r1, c1, r2, c2;
int check[201][201];
int res = -1;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

void bfs()
{
    queue<pair<int, int>> q;
    q.push({r1, c1});
    check[r1][c1] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == r2 && y == c2)
        {
            res = check[x][y];
            break;
        }

        for (int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx > n || ny > n)
                continue;

            if (check[nx][ny] != -1)
                continue;

            check[nx][ny] = check[x][y] + 1;
            q.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(check, -1, sizeof(check));

    bfs();

    cout<<res<<'\n';

    return 0;
}