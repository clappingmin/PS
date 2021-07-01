#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int n, m;
char map[1000][1000];
int tagging_map[1000][1000];
int tagging_size[1000000];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void tagging(int i, int j, int tag)
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    tagging_map[i][j] = tag;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (map[nx][ny] == '1' || tagging_map[nx][ny] != 0)
                continue;

            tagging_map[nx][ny] = tag;
            cnt++;
            q.push({nx, ny});
        }
    }
    tagging_size[tag] = cnt;
}

int count_place(int i, int j)
{
    set<int> s;
    int cnt = 1;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        if (map[nx][ny] == '1')
            continue;

        int tag = tagging_map[nx][ny];

        if (s.find(tag) == s.end())
        {
            s.insert(tag);
            cnt += tagging_size[tag];
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) //0.입력
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int tag = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '0' && tagging_map[i][j] == 0)
            {
                tagging(i, j, tag); // 1.그룹화
                tag++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '0')
                cout << map[i][j];
            else
                cout << count_place(i, j) % 10;
        }
        cout << '\n';
    }

    return 0;
}