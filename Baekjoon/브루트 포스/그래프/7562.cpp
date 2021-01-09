#include <iostream>
#include <queue>
#define MAX 300

using namespace std;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int map[MAX + 1][MAX + 1];
int n, x2, y2;

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

        if (x == x2 && y == y2)
            return;

        for (int direction = 0; direction < 8; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (map[nx][ny])
                continue;
            map[nx][ny] = map[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, x1, y1;

    cin >> t;

    while (t--)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                map[i][j] = 0;

        cin >> n;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        bfs(x1, y1);

        cout << map[x2][y2] << '\n';
    }

    return 0;
}