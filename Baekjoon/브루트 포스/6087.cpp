#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 987654321

using namespace std;

int w, h;
char map[100][100];
int check[100][100][4]; //map[x][y][방향]
int sx = -1, sy;        //시작 좌표
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j)
{
    queue<pair<pair<int, int>, int>> q;
    check[i][j][0] = check[i][j][1] = check[i][j][2] = check[i][j][3] = 0;  //시작점은 전부 0
    q.push(make_pair(make_pair(i, j), 0));
    q.push(make_pair(make_pair(i, j), 1));
    q.push(make_pair(make_pair(i, j), 2));
    q.push(make_pair(make_pair(i, j), 3));

    int res = MAX;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (map[x][y] == 'C')   //도착했으면
        {
            res = min(res, check[x][y][d]);
            continue;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;

            if (map[nx][ny] == '*')
                continue;

            if (d != dir && check[x][y][d] + 1 < check[nx][ny][dir])    //기존 방향과 다를 경우
            {
                check[nx][ny][dir] = check[x][y][d] + 1;
                q.push(make_pair(make_pair(nx, ny), dir));
            }
            else if (d == dir && check[x][y][d] < check[nx][ny][dir])   //기존 방향과 같을 경우
            {
                check[nx][ny][dir] = check[x][y][d];
                q.push(make_pair(make_pair(nx, ny), dir));
            }
        }
    }
    if (res != 987654321)
    cout<<res;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];

            for (int k = 0; k < 4; k++)
                check[i][j][k] = MAX;

            if (map[i][j] == 'C' && sx == -1)
            {
                sx = i;
                sy = j;
                map[i][j] = '.';
            }
        }
    }

    bfs(sx, sy);

    return 0;
}