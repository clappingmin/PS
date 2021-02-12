#include <iostream>
#include <queue>
using namespace std;

int n, res = 0;
int map[16][16];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

void count(int i, int j)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{i, j}, 0});

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int kind = q.front().second;

        q.pop();

        if (x == n - 1 && y == n - 1)
        {
            res++;
        }
        for (int dir = 0; dir < 3; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 1)
                continue;

            if (kind == 0 && dir == 2)  //가로 파이프일 경우 세로 파이프는 안된다.
                continue;

            if (kind == 2 && dir == 0) //세로 파이프일 경우 가로 파이프는 안된다.
                continue;

            if (dir == 1 && (map[x][y + 1] == 1 || map[x + 1][y] == 1)) //대각선 파이프를 놓을려면 주변에 벽이 있으면 안된다.
                continue;

            q.push({{nx, ny}, dir});
        }
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    count(0, 1); //시작점은 가로 파이프

    return 0;
}