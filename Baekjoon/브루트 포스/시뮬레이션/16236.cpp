#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
#define MAX 20

using namespace std;

int n;
int map[MAX][MAX];
int dist[MAX][MAX];
int shark_x, shark_y;
int min_x, min_y;
int shark_size = 2;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int find_fish()
{
    dist[shark_x][shark_y] = 0;
    queue<pair<int, int>> q;
    q.push({shark_x, shark_y});
    int min_dist = INT_MAX;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //범위를 벗어나거나
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            //이미 방문했거나 상어 크기보다 크면
            if (dist[nx][ny] != -1 || map[nx][ny] > shark_size)
                continue;
            
            //먹을 수 있는 물고기인 경우
            if (map[nx][ny] != 0 && map[nx][ny] < shark_size) 
            {
                //최단 거리보다 더 가까울 경우
                if (min_dist > dist[x][y] + 1) 
                {
                    min_dist = dist[x][y] + 1;
                    min_x = nx;
                    min_y = ny;
                }
                else if (min_dist == dist[x][y] + 1)
                {
                  if (min_x == nx && min_y > ny)
                    {
                        min_x = nx;
                        min_y = ny;
                    }

                    else if (min_x > nx)
                    {
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    if (min_dist == INT_MAX)
        return -1;

    return min_dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 9)
            {
                shark_x = i;
                shark_y = j;
                map[i][j] = 0;
            }
        }
    }
    int time = 0;
    int eat_cnt = 0;

    while (true)
    {
        memset(dist, -1, sizeof(dist));

        int find_time = find_fish();

        if (find_time == -1)
            break;

        shark_x = min_x;
        shark_y = min_y;
        time += find_time;
        map[min_x][min_y] = 0;
        eat_cnt += 1;

        if (eat_cnt == shark_size)
        {
            shark_size += 1;
            eat_cnt = 0;
        }
    }

    cout << time << '\n';

    return 0;
}