#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[100][100];
bool check[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void labeling(int i, int j, int label)
{
    check[i][j] = true;
    map[i][j] = label;
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (map[nx][ny] != 1 || check[nx][ny] == true)
                continue;

            map[nx][ny] = label;
            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int createbridge(int label)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) //모든 섬의 좌표를 넣는다
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == label)
            {
                check[i][j] = true;
                q.push({i, j});
            }
        }
    }
    int count = 0;

    while (!q.empty())
    {
        int island = q.size();
        for (int i = 0; i < island; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (map[nx][ny] != 0 && map[nx][ny] != label) //바다가 아니고 다른 섬에 도착할 경우
                    return count;

                else if (map[nx][ny] == 0 && check[nx][ny] == false) //바다이면서 아직 방문하지 않았을 경우
                {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        count++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    int label = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !check[i][j])
            {
                labeling(i, j, label);
                label += 1;
            }
        }
    }

    int res = 987654321;

    for (int i = 1; i < label; i++)
    {
        memset(check, false, sizeof(check));
        res = min(res, createbridge(i));
    }

    if (label <= 2)
        cout << 0 << '\n';
    else
        cout << res << '\n';

    return 0;
}