#include <iostream>
#include <queue>
#define MAX 50

using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int w, h;
int map[MAX][MAX];

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    map[i][j] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int direction = 0; direction < 8; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (!map[nx][ny])
                continue;

            map[nx][ny] = 0;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int res = 0;
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j]){
                    res++;
                    bfs(i,j);
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}