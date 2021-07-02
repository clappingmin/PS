#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int w, h;
char map[100][100];
int mirror_cnt[100][100][4];
int start_x = -1, start_y;
int res = INT_MAX;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void laser_bfs()
{
    queue<pair<pair<int, int>, int>> q;
    mirror_cnt[start_x][start_y][0] = mirror_cnt[start_x][start_y][1] = 0;
    mirror_cnt[start_x][start_y][2] = mirror_cnt[start_x][start_y][3] = 0;

    q.push({{start_x, start_y}, 0});
    q.push({{start_x, start_y}, 1});
    q.push({{start_x, start_y}, 2});
    q.push({{start_x, start_y}, 3});

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (map[x][y] == 'C')
        {
            res = min(res, mirror_cnt[x][y][d]);
            continue;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //범위를 벗어날 경우
            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
                continue;

            //벽일 경우
            if (map[nx][ny] == '*')
                continue;

            if (dir == d && mirror_cnt[x][y][d] < mirror_cnt[nx][ny][dir]) //방향이 같으면서 기존 거울 개수보다 작을 경우
            {
                mirror_cnt[nx][ny][dir] = mirror_cnt[x][y][d];
                q.push({{nx, ny}, dir});
            }
            else if (dir != d && mirror_cnt[x][y][d] + 1 < mirror_cnt[nx][ny][dir]) //방향이 다르면서 기존 거울 개수보다 작을 경우
            {
                mirror_cnt[nx][ny][dir] = mirror_cnt[x][y][d] + 1;
                q.push({{nx, ny}, dir});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'C' && start_x == -1)
            {
                start_x = i;
                start_y = j;
                map[i][j] = '.';
            }

            for (int d = 0; d < 4; d++)
            {
                mirror_cnt[i][j][d] = INT_MAX;
            }
        }
    }
    
    laser_bfs();

    cout << res << '\n';

    return 0;
}