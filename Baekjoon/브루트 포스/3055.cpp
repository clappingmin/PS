#include <iostream>
#include <queue>

using namespace std;

int r, c;
char map[51][51];
int after_rain[51][51];
int sx, sy;
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void rain() //1. 비 내리기
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (map[nx][ny] == 'X' || map[nx][ny] == 'D' || after_rain[nx][ny] != 987654321)  //바위, 비버굴, 이미 간 곳
                continue;

            after_rain[nx][ny] = after_rain[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}
void escape() //2. 탈출
{
    after_rain[sx][sy] = 0;
    q.push(make_pair(sx, sy));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (map[x][y] == 'D') // 탈출 성공
        {
            cout << after_rain[x][y] << '\n';
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (after_rain[nx][ny] <= after_rain[x][y] + 1)
                continue;

            after_rain[nx][ny] = after_rain[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << "KAKTUS" << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    //비어있는 곳 '.', 물이 차있는 지역은 '*'
    //돌은 'X', 비버의 굴은 'D'로, 고슴도치의 위치는 'S'
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            after_rain[i][j] = 987654321;

            if (map[i][j] == 'S') //고슴도치 시작점
            {
                sx = i;
                sy = j;
            }
            else if (map[i][j] == '*')  //비 시작점
            {
                q.push(make_pair(i, j));
                after_rain[i][j] = 0;
            }
            else if (map[i][j] == 'D')  //비버굴 (도착점)
            {
                after_rain[i][j] = 987654321;
            }
            else if (map[i][j] == 'X') //바위
            {
                after_rain[i][j] = -1;
            }
        }
    }

    //1. 비 내리기
    rain();

    //2. 탈출
    escape();

    return 0;
}