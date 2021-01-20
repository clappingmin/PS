#include <iostream>
#include <queue>
#include <cstring>
#define MAX 30
using namespace std;

int l, r, c;
char map[MAX][MAX][MAX]; //층,x,y;
int dist[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dz[6] = {-1, 1, 0, 0, 0, 0};
int dx[6] = {0, 0, -1, 0, 1, 0};
int dy[6] = {0, 0, 0, 1, 0, -1};

void bfs(int i, int j, int k)
{
    visited[i][j][k] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(i, j), k));

    while (!q.empty())
    {
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second;
        q.pop();

        if (map[z][x][y] == 'E') //탈출 성공
        {
            cout << "Escaped in " << dist[z][x][y] << " minute(s).\n";
            return;
        }
        else
        {
            for (int dir = 0; dir < 6; dir++)
            {
                int nz = z + dz[dir];
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c)
                    continue;
                if (map[nz][nx][ny] == '#' || visited[nz][nx][ny])
                    continue;

                visited[nz][nx][ny] = true;
                dist[nz][nx][ny] = dist[z][x][y] + 1;
                q.push(make_pair(make_pair(nz, nx), ny));
            }
        }
    }
    cout << "Trapped!\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int sz, sx, sy; //상범 시작 위치

        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0)
            return 0;

        memset(visited, false, sizeof(visited));
        memset(dist,0,sizeof(dist));
        
        for (int i = 0; i < l; i++) //입력
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S')
                    {
                        sz = i;
                        sx = j;
                        sy = k;
                    }
                }
            }
        }

        bfs(sz, sx, sy);

    }
    return 0;
}