#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
int time, res = 987654321;
int map[50][50], tmp[50][50];
int check_v[2501];

vector<pair<int, int>> virus, v;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void Spread_virus()
{
    queue<pair<int, int>> q;
    time = 0;

    for (int i = 0; i < v.size(); i++)
    {
        tmp[v[i].first][v[i].second] = 0;
        q.push(v[i]);
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (map[nx][ny] == 1 || tmp[nx][ny] != -1)
                //벽이거나 이미 방문 했으면
                continue;

            tmp[nx][ny] = tmp[x][y] + 1;
            q.push({nx, ny});

            if (time < tmp[nx][ny])
                time = tmp[nx][ny];
        }
    }
}

bool Check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 1 && tmp[i][j] == -1)
                return false;
        }
    }
    return true;
}

void Select(int index, int cnt)
{
    if (cnt == M)
    {
        memset(tmp, -1, sizeof(tmp));
        Spread_virus();

        if (Check())
        {
            res = min(res, time);
        }

        return;
    }

    for (int i = index; i < virus.size(); i++)
    {
        if (check_v[i] == true)
            continue;

        check_v[i] = true;
        v.push_back(virus[i]);

        Select(i, cnt + 1);

        check_v[i] = false;
        v.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    Select(0, 0);

    if (res == 987654321)
        cout << -1 << '\n';
    else
        cout << res << '\n';
}