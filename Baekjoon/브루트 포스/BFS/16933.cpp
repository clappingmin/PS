#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int n, m, k; //map의 크기, 벽 부수기 횟수
char map[1000][1000];
int dist[1000][1000][2][11];
int res = INT_MAX;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    //좌표 x,y, 낮인지 밤인지, 벽 부수기 남은 횟수
    q.push({{0, 0}, {0, k}}); //0, 0, 낮, 벽 부수기 횟수
    dist[0][0][0][k] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second.first;
        int wall = q.front().second.second;

        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            res = min(res, dist[x][y][day][wall]);
            continue;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int next_day = abs(day - 1);

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (map[nx][ny] == '0' && dist[nx][ny][next_day][wall] == 0) //빈 공간이면서 방문하지 않은 경우
            {
                dist[nx][ny][next_day][wall] = dist[x][y][day][wall] + 1;
                q.push({{nx, ny}, {next_day, wall}});
            }
            else if (map[nx][ny] == '1') //벽일 경우
            {
                if (wall > 0) //벽을 부술 횟수가 남아 있을 경우
                {
                    if (day == 0 && dist[nx][ny][next_day][wall - 1] == 0) //낮일 경우
                    {
                        dist[nx][ny][next_day][wall - 1] = dist[x][y][day][wall] + 1;
                        q.push({{nx, ny}, {next_day, wall - 1}});
                    }
                    else if (day == 1 && dist[x][y][next_day][wall] == 0) //밤일 경우
                    {
                        dist[x][y][next_day][wall] = dist[x][y][day][wall] + 1;
                        q.push({{x, y}, {next_day, wall}});
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    bfs();

    if (res == INT_MAX)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}