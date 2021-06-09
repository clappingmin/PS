#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> adjlist[101][101];
bool light[101][101], visited[101][101];
int cnt = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

static void initvisited()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            visited[i][j] = false;
}

void bfs()
{
    queue<pair<int, int>> q;
    initvisited();
    visited[1][1] = true;
    q.push({1, 1});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < adjlist[x][y].size(); i++) //불 켜기
        {
            int light_x = adjlist[x][y][i].first;
            int light_y = adjlist[x][y][i].second;

            if (!light[light_x][light_y])
            {
                light[light_x][light_y] = true;
                cnt++;
            }
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 1 || ny < 1 || nx > n || ny > n)
                continue;

            if (!light[nx][ny]) //불이 켜지지 않은 방
                continue;

            if (visited[nx][ny]) //이미 방문한 방
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        adjlist[x][y].push_back({a, b});
    }
    cnt = 1;
    light[1][1] = true;
    int before_cnt = 0;

    while (true)
    {
        before_cnt = cnt;
        bfs();

        if (before_cnt == cnt)
            break;
    }

    cout << cnt << '\n';

    return 0;
}