#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[50][50];
int check[50][50];
vector<pair<int, int>> virus;
vector<int> active_virus;
bool check_virus[251];
int empty_place = 0;
int time = 987654321;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void Spread_virus()
{
    memset(check, -1, sizeof(check));

    queue<pair<int, int>> q;

    for (int i = 0; i < M; i++)
    {
        int x = virus[active_virus[i]].first;
        int y = virus[active_virus[i]].second;
        q.push({x, y});
        check[x][y] = 0;
    }
    int total_time = 0;
    int place_cnt = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            if (map[nx][ny] == 1 || check[nx][ny] != -1)
                continue;

            check[nx][ny] = check[x][y] + 1;
            q.push({nx, ny});

            if (map[nx][ny] == 0)
            {
                place_cnt++;
                total_time = check[nx][ny];
            }
        }
    }

    if (empty_place == place_cnt)
        time = min(time, total_time);
}

void Choice_virus(int idx, int cnt)
{
    if (cnt == M)
    {
        Spread_virus(); //2.바이러스 퍼뜨리기
        return;
    }
    for (int i = idx; i < virus.size(); i++)
    {
        if (check_virus[i])
            continue;

        check_virus[i] = true;
        active_virus.push_back(i);
        Choice_virus(i, cnt + 1);
        active_virus.pop_back();
        check_virus[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2) //바이러스일 경우
                virus.push_back({i, j});
            else if (map[i][j] == 0)
                empty_place++;
        }
    }

    Choice_virus(0, 0); //1.활성 바이러스 선택하기

    if (time == 987654321)
        cout << -1 << '\n';
    else
        cout << time << '\n';

    return 0;
}