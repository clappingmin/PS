#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n, l, r;
int map[50][50];
int visited[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;   //bfs용
queue<pair<int, int>> pos; //연합국가 저장용
bool check = true;
int cnt = 0;

void bfs()
{
    while (check)
    {
        cnt++;
        check = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == cnt)
                    continue;
                int sum = map[i][j];
                q.push({i, j});
                pos.push({i, j});
                visited[i][j] = cnt;

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

                        if (visited[nx][ny] == cnt || abs(map[x][y] - map[nx][ny]) < l || abs(map[x][y] - map[nx][ny]) > r)
                            continue;

                        check = true;
                        q.push({nx, ny});
                        pos.push({nx, ny});
                        sum += map[nx][ny];
                        visited[nx][ny] = cnt;
                    }
                }

                int avr = sum / pos.size();

                while (!pos.empty())
                {
                    map[pos.front().first][pos.front().second] = avr;
                    pos.pop();
                }
            }
        }
    }
}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    bfs();

    cout << cnt - 1 << '\n';

    return 0;
}