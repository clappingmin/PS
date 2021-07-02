#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int map[20][20];
int dist[20][20];
int shark_x, shark_y;
int shark_size = 2;
int min_x, min_y;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int find_fish()
{
    queue<pair<int, int>> q;
    q.push({shark_x, shark_y});
    dist[shark_x][shark_y] = 0;
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
            
            // 범위 밖인 경우
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            //상어 크기보다 큰 물고기인 경우, 이미 방문한 경우
            if (map[nx][ny] > shark_size || dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
            
            //먹을 수 있는 물고기인 경우
            if (shark_size > map[nx][ny] && map[nx][ny] != 0)
            {   
                //최단 거리보다 작은 경우
                if (min_dist > dist[nx][ny])
                {
                    min_dist = dist[nx][ny];
                    min_x = nx;
                    min_y = ny;
                }
                //최단 거리와 같은 경우
                else if (min_dist == dist[nx][ny])
                {   
                    //가장 위쪽, 왼쪽
                    if (min_x == nx && min_y > ny)
                    {
                        min_dist = dist[nx][ny];
                        min_x = nx;
                        min_y = ny;
                    }

                    else if (min_x > nx)
                    {
                        min_dist = dist[nx][ny];
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
        }
    }
    //먹을 수 있는 물고기가 없는 경우
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

        //먹을 수 있는 물고기를 못 찾음
        if (find_time == -1)
            break;

        time += find_time;
        shark_x = min_x;
        shark_y = min_y;
        map[min_x][min_y] = 0;
        eat_cnt += 1;


        //먹은 물고기 수가 상어의 크기와 같으면 
        if (eat_cnt == shark_size)
        {
            eat_cnt = 0;
            shark_size += 1;
        }
    }


    // cout<<"====================\n";
    // for(int i =0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<map[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    cout << time << '\n';

    return 0;
}