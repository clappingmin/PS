#include <iostream>
#include <queue>
using namespace std;

int n, m, t; //성 크기, 제한 시간
int gx, gy;  //그람 좌표
int map[100][100];
int check[100][100][2]; //그람 유무
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    check[0][0][0] = 0; //시작점

    if (gx == 0 && gy == 0)
        q.push(make_pair(make_pair(0, 0), 1));

    else
        q.push(make_pair(make_pair(0, 0), 0));

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int gram = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) //도착했을 경우
            return check[x][y][gram];

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (gram == 0) //그람이 없을 경우
            {
                if (map[nx][ny] == 1 || check[nx][ny][gram] != 0)
                    continue;

                if (map[nx][ny] == 2) //그람을 발견하면
                {
                    check[nx][ny][0] = check[nx][ny][1] = check[x][y][gram] + 1;
                    q.push(make_pair(make_pair(nx, ny), 1));
                }
                else if (map[nx][ny] == 0)
                {
                    check[nx][ny][gram] = check[x][y][gram] + 1;
                    q.push(make_pair(make_pair(nx, ny), 0));
                }
            }
            else if (gram == 1) //그람이 있을 경우
            {
                if (check[nx][ny][gram] != 0)
                    continue;

                check[nx][ny][gram] = check[x][y][gram] + 1;
                q.push(make_pair(make_pair(nx, ny), 1));
            }
        }
    }
    return 10001;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 2)
            {
                gx = i;
                gy = j;
                map[i][j] = 2;
            }
        }
    }

    int res = bfs();

    if (t < res)
        cout << "Fail\n";
    else
        cout << res << '\n';
}