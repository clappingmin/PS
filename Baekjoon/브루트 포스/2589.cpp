#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
char map[50][50];
int visited[50][50];
int dist = 0;

vector<pair<int, int>> island;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS()
{
    for (int i = 0; i < island.size(); i++)
    {
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push(island[i]);
        visited[island[i].first][island[i].second] = 1;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;

                if (map[nx][ny] == 'W' || visited[nx][ny] != 0)
                    //바다이거나 이미 방문한 경우
                    continue;

                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});

                if (visited[nx][ny] > dist)
                    dist = visited[nx][ny];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'L')
            {
                island.push_back({i, j});
            }
        }
    }
    BFS();

    cout << dist - 1 << '\n';

    return 0;
}