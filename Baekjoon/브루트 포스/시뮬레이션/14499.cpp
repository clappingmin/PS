#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int n, m, sx, sy, k;
int map[20][20];
deque<int> cmd;
int dice[7] = {0};

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void RollDice(int d)
{
    int d1 = dice[1];
    int d2 = dice[2];
    int d3 = dice[3];
    int d4 = dice[4];
    int d5 = dice[5];
    int d6 = dice[6];

    if (d == 1) //동쪽
    {
        dice[1] = d4;
        dice[3] = d1;
        dice[6] = d3;
        dice[4] = d6;
    }
    else if (d == 2) //서쪽
    {
        dice[1] = d3;
        dice[4] = d1;
        dice[6] = d4;
        dice[3] = d6;
    }
    else if (d == 3) //북쪽
    {
        dice[1] = d5;
        dice[5] = d6;
        dice[6] = d2;
        dice[2] = d1;
    }
    else if (d == 4) //남쪽
    {
        dice[1] = d2;
        dice[5] = d1;
        dice[6] = d5;
        dice[2] = d6;
    }
}
void solution()
{
    int x = sx;
    int y = sy;
    int c = cmd.size();

    for (int i = 0; i < c; i++)
    {
        int d = cmd.front();
        cmd.pop_front();

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        RollDice(d);

        if (map[nx][ny] == 0)
            map[nx][ny] = dice[6];

        else
        {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout << dice[1] << '\n';

        x = nx;
        y = ny;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> sx >> sy >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        cmd.push_back(a);
    }

    solution();


    return 0;
}