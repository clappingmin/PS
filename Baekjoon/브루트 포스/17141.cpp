#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#define MAX 987654321

using namespace std;

int n, m; //연구소 크기, 놓을 바이러스 개수
int map[50][50];
int check[50][50];
int res = MAX;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int>> q;
vector<pair<int, int>> v;
int v_check[2501];

void spread(deque<pair<int, int>> q) // 2. 바이러스 퍼뜨리기
{
    for (int i = 0; i < q.size(); i++)
        check[q[i].first][q[i].second] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (map[nx][ny] == 1 || check[nx][ny] != -1)
                continue;

            check[nx][ny] = check[x][y] + 1;
            q.push_back(make_pair(nx, ny));
        }
    }
}

int complete() // 3. 빈 칸 없이 다 퍼진지 확인
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] != 1 && check[i][j] == -1) //벽이 아닌데 바이러스가 퍼지지 않은 곳이 있다면
                return MAX;
            else
            {
                if (check[i][j] > temp)
                    temp = check[i][j];
            }
        }
    }
    return temp;
}

void go(int cnt, int index)  //1. 바이러스 놓기
{
    if (cnt == m)
    {
        memset(check, -1, sizeof(check));
        spread(q);   // 2. 바이러스 퍼뜨리기
        res = min(res, complete()); // 3. 빈 칸 없이 다 퍼진지 확인, 결과 비교

        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        if (v_check[i] == false)
        {
            v_check[i] = true;
            q.push_back(v[i]);
            go(cnt + 1, i);
            q.pop_back();
            v_check[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 2)
                v.push_back(make_pair(i, j));
        }
    }

    //1. 바이러스 놓기
    go(0, 0);

    if (res == MAX)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}
