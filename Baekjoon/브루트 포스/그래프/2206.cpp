#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX];
int dist[MAX][MAX][2]; //마지막은 벽 뚫었는지

int bfs()
{
        queue<pair<pair<int, int>, int>> q;    //y, x, 벽 뚫기
        q.push(make_pair(make_pair(0, 0), 1)); //시작점, 벽 뚫기 가능
        dist[0][0][1] = 1;

        while (!q.empty())
        {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int block = q.front().second;

                q.pop();

                if (x == n - 1 && y == m - 1)
                        return dist[x][y][block];

                for (int dir = 0; dir < 4; dir++)
                {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                                continue;

                        if (map[nx][ny] == 1 && block == 1) //벽이 있고 벽을 안뚫었으면
                        {
                                dist[nx][ny][block - 1] = dist[x][y][block] + 1;
                                q.push(make_pair(make_pair(nx, ny), block - 1));
                        }

                        else if (map[nx][ny] == 0 && dist[nx][ny][block] == 0) //벽이 없고 방문하지 않았으면
                        {
                                dist[nx][ny][block] = dist[x][y][block] + 1;
                                q.push(make_pair(make_pair(nx, ny), block));
                        }
                }
        }
        return -1;
}

int main()
{
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        scanf("%1d", &map[i][j]);
                }
        }

        cout << bfs() << '\n';

        return 0;
}