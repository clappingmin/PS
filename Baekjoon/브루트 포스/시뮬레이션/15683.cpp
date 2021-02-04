#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cctv_num;
int res = 987654321;
int map[8][8];
int tempmap[8][8];
vector<pair<pair<int, int>, pair<int, int>>> cctv; //cctv좌표, cctv번호, 방향

void copymap()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tempmap[i][j] = map[i][j];
}

void right(int x, int y)
{
    for (int i = y + 1; i < m; i++)
    {
        if (tempmap[x][i] == 6)
            break;
        if (tempmap[x][i] >= 1 && tempmap[x][i] >= 6)
            continue;
        tempmap[x][i] = -1;
    }
}
void left(int x, int y)
{
    for (int i = y - 1; i >= 0; i--)
    {
        if (tempmap[x][i] == 6)
            break;
        if (tempmap[x][i] >= 1 && tempmap[x][i] >= 6)
            continue;
        tempmap[x][i] = -1;
    }
}
void up(int x, int y)
{
    for (int i = x - 1; i >= 0; i--)
    {
        if (tempmap[i][y] == 6)
            break;
        if (tempmap[i][y] >= 1 && tempmap[i][y] >= 6)
            continue;
        tempmap[i][y] = -1;
    }
}
void down(int x, int y)
{
    for (int i = x + 1; i < n; i++)
    {
        if (tempmap[i][y] == 6)
            break;
        if (tempmap[i][y] >= 1 && tempmap[i][y] >= 6)
            continue;
        tempmap[i][y] = -1;
    }
}

int count_area()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (tempmap[i][j] == 0)
                cnt++;
    }
    return cnt;
}
void check_area()
{
    copymap();
    for (int i = 0; i < cctv_num; i++)
    {
        if (cctv[i].second.first == 1)
        {
            if (cctv[i].second.second == 0)
                right(cctv[i].first.first, cctv[i].first.second);
            else if (cctv[i].second.second == 1)
                left(cctv[i].first.first, cctv[i].first.second);
            else if (cctv[i].second.second == 2)
                up(cctv[i].first.first, cctv[i].first.second);
            else if (cctv[i].second.second == 3)
                down(cctv[i].first.first, cctv[i].first.second);
        }
        if (cctv[i].second.first == 2)
        {
            if (cctv[i].second.second == 0 || cctv[i].second.second == 1)
            {
                right(cctv[i].first.first, cctv[i].first.second);
                left(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 2 || cctv[i].second.second == 3)
            {
                up(cctv[i].first.first, cctv[i].first.second);
                down(cctv[i].first.first, cctv[i].first.second);
            }
        }

        if (cctv[i].second.first == 3)
        {
            if (cctv[i].second.second == 0)
            {
                right(cctv[i].first.first, cctv[i].first.second);
                up(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 1)
            {
                up(cctv[i].first.first, cctv[i].first.second);
                left(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 2)
            {
                left(cctv[i].first.first, cctv[i].first.second);
                down(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 3)
            {
                right(cctv[i].first.first, cctv[i].first.second);
                down(cctv[i].first.first, cctv[i].first.second);
            }
        }
        if (cctv[i].second.first == 4)
        {
            if (cctv[i].second.second == 0)
            {
                right(cctv[i].first.first, cctv[i].first.second);
                up(cctv[i].first.first, cctv[i].first.second);
                left(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 1)
            {
                up(cctv[i].first.first, cctv[i].first.second);
                left(cctv[i].first.first, cctv[i].first.second);
                down(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 2)
            {
                left(cctv[i].first.first, cctv[i].first.second);
                down(cctv[i].first.first, cctv[i].first.second);
                right(cctv[i].first.first, cctv[i].first.second);
            }
            else if (cctv[i].second.second == 3)
            {
                right(cctv[i].first.first, cctv[i].first.second);
                down(cctv[i].first.first, cctv[i].first.second);
                up(cctv[i].first.first, cctv[i].first.second);
            }
        }
        if (cctv[i].second.first == 5)
        {
            right(cctv[i].first.first, cctv[i].first.second);
            left(cctv[i].first.first, cctv[i].first.second);
            up(cctv[i].first.first, cctv[i].first.second);
            down(cctv[i].first.first, cctv[i].first.second);
        }
    }
}

void direction(int cnt)
{
    if (cnt == cctv_num)
    {
        check_area();
        res = min(res, count_area());
        return;
    }
    cctv[cnt].second.second = 0; //cctv가 0번 방향일 때
    direction(cnt + 1);

    cctv[cnt].second.second = 1; //cctv가 1번 방향일 때
    direction(cnt + 1);

    cctv[cnt].second.second = 2; //cctv가 2번 방향일 때
    direction(cnt + 1);

    cctv[cnt].second.second = 3; //cctv가 3번 방향일 때
    direction(cnt + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] != 0 && map[i][j] != 6)
                cctv.push_back(make_pair(make_pair(i, j), make_pair(map[i][j], -1)));
        }
    }
    cctv_num = cctv.size();

    direction(0);

    cout << res << '\n';
}