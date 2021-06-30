#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int n, m;
vector<pair<int, int>> wall;
char map[1000][1000];
int check[1000][1000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int area_cnt[1000000];

void tagging(int i, int j, int tag)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    check[i][j] = tag;
    cnt++;

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

            if (check[nx][ny] != -1 || map[nx][ny] - '0' != 0)
                continue;

            check[nx][ny] = tag;
            cnt++;
            q.push({nx, ny});
        }
    }
    area_cnt[tag] = cnt;
}

int count_place(int i, int j)
{
    set<int> s; //중복 검사를 위해서
    int sum = 1;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        int tag = check[nx][ny];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        if (map[nx][ny] == '1')
            continue;

        if (s.find(tag) == s.end()) //확인하지 않은 그룹의 tag일 경우
        {
            sum += area_cnt[tag];
            s.insert(tag);
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int tag = 0;

    memset(check, -1, sizeof(check));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] - '0' == 0 && check[i][j] == -1) //1. 그룹화하기
            {
                tagging(i, j, tag);
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
            if (map[i][j] == '1')
            {
                cout << count_place(i, j) % 10;
            }
        }
        cout << '\n';
    }

    return 0;
}