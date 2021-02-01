#include <iostream>
#include <queue>
#include <cstring>
#define MAX 8

using namespace std;

int n, m, res = 0;
int map[MAX][MAX];
int temp[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool check[MAX][MAX];

void mapcopy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = map[i][j];
        }
    }
    return;
}
void spreadvirus()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    int i = q.front().first;
    int j = q.front().second;
    check[i][j] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (check[nx][ny] || temp[nx][ny] != 0)
                continue;

            temp[nx][ny] = 2;
            check[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    return;
}
void countblankspace()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
                cnt++;
        }
    }
    if (res < cnt)
        res = cnt;
}
void makewall(int cnt)
{
    if (cnt == 3)  
    {
        memset(check, false, sizeof(check));

        mapcopy();      //2. 맵을 복사한다.
        spreadvirus();  //3. 복사한 맵에 바이러스 뿌리기
        countblankspace();  //4. 빈 공간 검사하기

        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                makewall(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];


    makewall(0);    //1. 벽세우기

    cout << res << '\n';

    return 0;
}