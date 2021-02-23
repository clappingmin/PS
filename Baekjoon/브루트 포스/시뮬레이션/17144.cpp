#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;

int r, c, t;
int air_x = -1, air_y = -1;
int map[MAX][MAX];
int copy_map[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, int>> dust;

void copy()
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            map[i][j] = copy_map[i][j];
}

void spread_dust()
{
    int cnt = dust.size();

    for (int i = 0; i < cnt; i++)
    {
        queue<pair<int, int>> next_location;

        int x = dust.front().first.first;
        int y = dust.front().first.second;
        int amount = dust.front().second;
        dust.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (nx == air_x && ny == air_y)
                continue;
            if (nx == air_x + 1 && ny == air_y)
                continue;

            next_location.push({nx, ny});
        }

        int n_cnt = next_location.size();

        for (int j = 0; j < n_cnt; j++)
        {
            int nx = next_location.front().first;
            int ny = next_location.front().second;
            next_location.pop();

            copy_map[nx][ny] += amount / 5;
        }
        copy_map[x][y] += amount - (amount / 5) * n_cnt;
    }
    copy_map[air_x][air_y] = -1; //공기청정기 위치 표시
    copy_map[air_x + 1][air_y] = -1;
}

void run_air_purifier()
{
    for (int i = 0; i < r; i++)
    {
        if (i <= air_x) //공기청정기 위 (반시계 방향 동작)
        {
            if (i + 1 != air_x)
                copy_map[i + 1][air_y] = map[i][air_y]; //아래 방향 동작

            if (i - 1 >= 0)
                copy_map[i - 1][c - 1] = map[i][c - 1]; //위 방향 동작
        }
        else //공기청정기 아래 (시계 방향 동작)
        {
            if (i + 1 < r)
                copy_map[i + 1][c - 1] = map[i][c - 1]; //아래 방향 동작

            if (i - 1 != air_x + 1)
                copy_map[i - 1][air_y] = map[i][air_y]; //위 방향 동작
        }
        if (i == 0 || i == r - 1)
        {
            for (int j = 1; j < c; j++)
            {
                copy_map[i][j - 1] = map[i][j];
            }
        }
        else if (i == air_x || i == air_x + 1)
        {
            for (int j = c - 1; j > 1; j--)
                copy_map[i][j] = map[i][j - 1];
        }
    }
    for (int i = 1; i < r - 1; i++) //공기청정기 돌아가지 않는 곳도 copy_map에 옮겨 준다.
    {
        for (int j = 1; j < c - 1; j++)
        {
            if (i == air_x || i == air_x + 1)
                continue;
            copy_map[i][j] = map[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == -1 && air_x == -1) //공기청정기 위치 저장
            {
                air_x = i;
                air_y = j;
            }
            //공기청정기는 {air_x,air_y},{air_x+1,air_y}에 있음
        }
    }

    while (t--)
    {
        for (int i = 0; i < r; i++) //1. 미세먼지 좌표를 다 저장
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] > 0)
                    dust.push({{i, j}, map[i][j]});
            }
        }

        //2.미세먼지 확산
        spread_dust();
        copy();
        memset(copy_map, 0, sizeof(copy_map));

        //3. 공기청정기 작동
        run_air_purifier();
        copy();
        memset(copy_map, 0, sizeof(copy_map));
    }

    int res = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            if (map[i][j] != -1)
                res += map[i][j];
    }
    cout << res << '\n';

    return 0;
}