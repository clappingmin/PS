#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M, K;
int map[1000][1000];
int dist[1000][1000][10]; //초능력 횟수

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void BFS()
{
    queue<pair<pair<int, int>, int>> q;
    dist[0][0][0] = 1;
    q.push({{0, 0}, 0});

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int num = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1) //도착했을 경우
        {
            cout << dist[x][y][num] << '\n';
            return;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (map[nx][ny] == 0 && dist[nx][ny][num] == 0)
            {
                dist[nx][ny][num] = dist[x][y][num] + 1;
                q.push({{nx, ny}, num});
            }
            else if (map[nx][ny] == 1 && dist[nx][ny][num + 1] == 0)
            {
                if (num < K)
                {
                    dist[nx][ny][num + 1] = dist[x][y][num] + 1;
                    q.push({{nx, ny}, num + 1});
                }
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = s[j]-'0';
        }
    }

    BFS();

    return 0;
}