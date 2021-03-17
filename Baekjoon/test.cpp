#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int N, L, R;
int map[50][50];
int visited[50][50];
int th = 0;
bool check = true;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> pos; //연합국가 저장

void BFS()
{
    queue<pair<int, int>> q;
    while (check)
    {
        check = false;
        th++;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == th)
                    continue;

                int sum = map[i][j];
                q.push({i, j});
                pos.push({i, j});
                visited[i][j] = th;

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

                        if (visited[nx][ny] == th || abs(map[x][y] - map[nx][ny]) < L || abs(map[x][y] - map[nx][ny]) > R)
                            continue;

                        q.push({nx, ny});
                        pos.push({nx, ny});
                        sum += map[nx][ny];
                        visited[nx][ny] = th;
                        check = true;
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
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    BFS();

    cout << th - 1;

    return 0;
}