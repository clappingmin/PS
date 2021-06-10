#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, p;
int s[10];
int res[10];
char map[1000][1000];
queue<pair<pair<int, int>, int>> q[10];
queue<pair<pair<int, int>, int>> nq[10];
int temp = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int idx)
{
    while (!q[idx].empty())
    {
        int x = q[idx].front().first.first;
        int y = q[idx].front().first.second;
        int cnt = q[idx].front().second;

        q[idx].pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (map[nx][ny] != '.')
                continue;

            map[nx][ny] = map[x][y];
            temp++;

            if (cnt + 1 == s[idx]) 
             //확장 횟수가 마지막인 공간은 다음 게임에 사용할 q에 넣는다.
                nq[idx].push({{nx, ny}, 0});

            else
                q[idx].push({{nx, ny}, cnt + 1});
        }
    }
}
void set_q(int i)
{
        q[i] = nq[i];

        while (!nq[i].empty())
            nq[i].pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> p;

    for (int i = 1; i <= p; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] != '.' && map[i][j] != '#')
            {
                int idx = map[i][j] - '0';
                q[idx].push({{i, j}, 0});
            }
        }
    }

    for (int i = 1; i <= p; i++)
        res[i] = q[i].size();

    while (true)
    {
        bool flag_change = false;

        for (int i = 1; i <= p; i++)
        {
            temp = 0;
            bfs(i);
            if (temp != 0)
            {
                flag_change = true;
                res[i] += temp;
            }

            set_q(i);
        }
        if (!flag_change)
           //모든 플레이어가 확장이 더이상 안될 경우
            break;
    }
    for (int i = 1; i <= p; i++)
        cout << res[i] << " ";

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << map[i][j];
    //     }
    //     cout << '\n';
    // }

    return 0;
}