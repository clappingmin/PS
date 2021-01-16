#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1000

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int w, h; //너비,높이
int firelater[MAX][MAX];
bool check[MAX][MAX];
char map[MAX][MAX];
queue<pair<int, int>> fire;

void setfire()
{
    while (!fire.empty())
    {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;

            if (map[nx][ny] == '#' || firelater[nx][ny])
                continue;

            firelater[nx][ny] = firelater[x][y] + 1;
            fire.push(make_pair(nx, ny));
        }
    }
    return;
}
int escape(int i, int j)
{
    check[i][j] = true;
    firelater[i][j] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == h - 1 || y == 0 || y == w - 1)
        {
            return firelater[x][y];
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (map[nx][ny] == '#' || check[nx][ny])
                continue;
            if (firelater[nx][ny] != 0 && firelater[nx][ny] <= firelater[x][y] + 1)
                continue;

            firelater[nx][ny] = firelater[x][y] + 1;
            check[nx][ny] = true;

            q.push(make_pair(nx, ny));
        }
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int px, py; //사람 시작 좌표
        int res = 0;
        cin >> w >> h;

        memset(check, false, sizeof(check));
        memset(firelater, false, sizeof(firelater));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == '*')
                {
                    fire.push(make_pair(i, j));
                    firelater[i][j] = 1;
                }
                else if (map[i][j] == '@')
                {
                    px = i;
                    py = j;
                }
            }
        }

        //불지르기
        setfire();

        //탈출
        res = escape(px, py);

        if (res)
            cout << res << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}