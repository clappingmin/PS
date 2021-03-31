#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[100][100];
bool visited[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int time = 0, res = 0, cnt = 0;

void BFS()
{
    while (true)
    {
        cnt = 0;

        for (int i = 0; i < N; i++) //2. 치즈 세기
            for (int j = 0; j < M; j++)
                if (map[i][j] == 1)
                    cnt++;

        if (cnt == 0)
            break;

        else
        {
            time += 1;
            res = cnt;
        }

        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) //1. 치즈 녹이기
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
                if (visited[nx][ny])
                    continue;

                if (map[nx][ny] == 0) //공기일경우
                    q.push({nx, ny});
                else if (map[nx][ny] == 1) //치즈일경우
                    map[nx][ny] = 0;

                visited[nx][ny] = true;
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
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    BFS();

    cout << time << '\n'
         << res << '\n';

    return 0;
}