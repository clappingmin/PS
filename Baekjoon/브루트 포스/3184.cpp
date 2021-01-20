#include <iostream>
#include <vector>
#include <queue>
#define MAX 250

using namespace std;

int r, c;
int s = 0, w = 0; //양, 늑대 수
char map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> v;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j)
{
    visited[i][j] == true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int tmps = 0; //구역 양의 수
    int tmpw = 0; //구역 늑대의 수

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (visited[nx][ny])
                continue;
            if (map[nx][ny] == '#')
                continue;
            else
            {
                if (map[nx][ny] == 'o')
                    tmps++;
                else if (map[nx][ny] == 'v')
                    tmpw++;
            }
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    if (tmps > tmpw)
        w -= tmpw;
    else
        s -= tmps;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'o')
            {
                s++;
                v.push_back(make_pair(i, j));
            }
            else if (map[i][j] == 'v')
            {
                w++;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (visited[v[i].first][v[i].second] == false)
        {
            bfs(v[i].first, v[i].second);
        }
    }

    cout << s << ' ' << w << '\n';

    return 0;
}