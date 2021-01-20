#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1500

using namespace std;

int r, c;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool meet(int i, int j)
{
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (map[x][y] == 'L' && x != i && y != j)
            return true;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (map[nx][ny] == 'X' || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    return false;
}

void melting(int i, int j)
{
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

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
            if (map[nx][ny] == 'X')
            {
                map[nx][ny] = '.';
                visited[nx][ny] = true;
                continue;
            }
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lx, ly; //백조 하나의 좌표
    int day = 0;

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'L')
            {
                lx = i;
                ly = j;
            }
        }
    }
    //처음에도 만날 수 있는지 체크
    if (meet(lx, ly))
    {
        cout << day << '\n';
        return 0;
    }

    while (true)
    {
        memset(visited, false, sizeof(visited));

        //얼음 녹이기
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] == '.' && !visited[i][j])
                    melting(i, j);
            }
        }
        day++;

        memset(visited, false, sizeof(visited));

        if (meet(lx, ly))
        {
            cout << day << '\n';
            return 0;
        }
    }
    return 0;
}