#include <iostream>
#include <queue>
#define MAX 200

using namespace std;

int k, w, h; //초능력, 가로, 세로
int map[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int px[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int py[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dist[MAX][MAX][31];     //능력 횟수
bool visited[MAX][MAX][31]; //능력 횟수

int bfs()
{
    visited[0][0][0] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        q.pop();

        if (x == h - 1 && y == w - 1) //도착했을 경우
            return dist[x][y][num];

        //초능력을 아직 쓸수 있을 경우
        if (num < k)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = x + px[dir];
                int ny = y + py[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (map[nx][ny] == 1 || visited[nx][ny][num + 1])
                    continue;

                visited[nx][ny][num + 1] = true;
                dist[nx][ny][num + 1] = dist[x][y][num] + 1;
                q.push(make_pair(make_pair(nx, ny), num + 1));
            }
        }
        //그냥 이동할 경우
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (map[nx][ny] == 1 || visited[nx][ny][num])
                continue;

            visited[nx][ny][num] = true;
            dist[nx][ny][num] = dist[x][y][num] + 1;
            q.push(make_pair(make_pair(nx, ny), num));
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> w >> h;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> map[i][j];

    cout << bfs() << '\n';

    return 0;
}