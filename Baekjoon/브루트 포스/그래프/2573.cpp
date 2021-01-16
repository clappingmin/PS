#include <iostream>
#include <queue>
#include <cstring>
#define MAX 300

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX];
bool check[MAX][MAX];

void yearlater(int i, int j)
{
    check[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (map[nx][ny] == 0 && !check[nx][ny])
            {
                if (map[x][y] > 0)
                    map[x][y] -= 1;
            }
            else if (map[nx][ny] && !check[nx][ny])
            {
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
void count(int i, int j)
{
    check[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (!map[nx][ny] || check[nx][ny])
                continue;

            check[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int year = 0;
    int cnt = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    while (cnt < 2)
    {

        cnt = 0;
        memset(check, false, sizeof(check));

        //1 빙산녹이기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] && !check[i][j])
                {
                    yearlater(i, j);
                }
            }
        }
        year++;
        memset(check, false, sizeof(check));

        //2 빙산 수 세기
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] && !check[i][j])
                {
                    count(i, j);
                    cnt++;
                }
            }
        }
        if (cnt == 0)
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << year << '\n';

    return 0;
}