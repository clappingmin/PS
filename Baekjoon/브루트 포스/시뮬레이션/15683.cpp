#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int map[8][8], tmp_map[8][8];
int empty_cnt = 987654321;
int cctv_cnt;

vector<pair<pair<int, int>, pair<int, int>>> cctv; //좌표, 번호, 방향

void Copy_map()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            tmp_map[i][j] = map[i][j];
}

void up(int r, int c)
{
    for (int i = r - 1; i >= 0; i--)
    {
        if (tmp_map[i][c] == 6)
            break;

        else if (1 <= tmp_map[i][c] && tmp_map[i][c] <= 5)
            continue;

        tmp_map[i][c] = -1;
    }
}
void down(int r, int c)
{
    for (int i = r + 1; i < N; i++)
    {
        if (tmp_map[i][c] == 6)
            break;

        else if (1 <= tmp_map[i][c] && tmp_map[i][c] <= 5)
            continue;

        tmp_map[i][c] = -1;
    }
}
void left(int r, int c)
{
    for (int i = c - 1; i >= 0; i--)
    {
        if (tmp_map[r][i] == 6)
            break;
        else if (1 <= tmp_map[r][i] && tmp_map[r][i] <= 5)
            continue;

        tmp_map[r][i] = -1;
    }
}
void right(int r, int c)
{
    for (int i = c + 1; i < M; i++)
    {
        if (tmp_map[r][i] == 6)
            break;
        else if (1 <= tmp_map[r][i] && tmp_map[r][i] <= 5)
            continue;

        tmp_map[r][i] = -1;
    }
}

int Count_empty()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp_map[i][j] == 0)
                res += 1;
        }
    }
    return res;
}

void Setting_cctv()
{
    Copy_map();

    for (int i = 0; i < cctv_cnt; i++)
    {
        int cctv_num = cctv[i].second.first;
        int cctv_dir = cctv[i].second.second;
        int x = cctv[i].first.first;
        int y = cctv[i].first.second;

        if (cctv_num == 1)
        {
            if (cctv_dir == 0)
                up(x, y);
            else if (cctv_dir == 1)
                down(x, y);
            else if (cctv_dir == 2)
                left(x, y);
            else if (cctv_dir == 3)
                right(x, y);
        }
        else if (cctv_num == 2)
        {
            if (cctv_dir == 0 || cctv_dir == 1)
            {
                up(x, y);
                down(x, y);
            }
            else if (cctv_dir == 2 || cctv_dir == 3)
            {
                left(x, y);
                right(x, y);
            }
        }
        else if (cctv_num == 3)
        {
            if (cctv_dir == 0)
            {
                up(x, y);
                left(x, y);
            }
            else if (cctv_dir == 1)
            {
                up(x, y);
                right(x, y);
            }
            else if (cctv_dir == 2)
            {
                down(x, y);
                left(x, y);
            }
            else if (cctv_dir == 3)
            {
                down(x, y);
                right(x, y);
            }
        }
        else if (cctv_num == 4)
        {
            if (cctv_dir == 0)
            {
                up(x, y);
                left(x, y);
                right(x, y);
            }
            else if (cctv_dir == 1)
            {
                up(x, y);
                left(x, y);
                down(x, y);
            }
            else if (cctv_dir == 2)
            {
                down(x, y);
                left(x, y);
                right(x, y);
            }
            else if (cctv_dir == 3)
            {
                up(x, y);
                down(x, y);
                right(x, y);
            }
        }
        else if (cctv_num == 5)
        {

            up(x, y);
            down(x, y);
            left(x, y);
            right(x, y);
        }
    }
}

void Select_direction(int cnt)
{
    if (cnt == cctv_cnt)
    {
        Setting_cctv();
        empty_cnt = min(empty_cnt, Count_empty());
        return;
    }

    cctv[cnt].second.second = 0;
    Select_direction(cnt + 1);

    cctv[cnt].second.second = 1;
    Select_direction(cnt + 1);

    cctv[cnt].second.second = 2;
    Select_direction(cnt + 1);

    cctv[cnt].second.second = 3;
    Select_direction(cnt + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if (1 <= map[i][j] && map[i][j] <= 5)
                cctv.push_back({{i, j}, {map[i][j], -1}});
        }
    }
    cctv_cnt = cctv.size();

    Select_direction(0);

    cout << empty_cnt << '\n';

    return 0;
}