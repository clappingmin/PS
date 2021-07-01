#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[8][8];
queue<pair<int, int>> wall;
queue<pair<int, int>> next_wall;
queue<pair<int, int>> wook;
queue<pair<int, int>> next_wook;

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void q_set()
{
    while (!next_wall.empty())
    {
        int x = next_wall.front().first;
        int y = next_wall.front().second;

        map[x][y] = '#';
        next_wall.pop();
    }

    while (!next_wook.empty())
        next_wook.pop();
}

void move_wall()
{
    while (!wall.empty())
    {
        int x = wall.front().first;
        int y = wall.front().second;
        wall.pop();

        int nx = x + 1;

        map[x][y] = '.';

        if (nx < 0 || nx >= 8)
            continue;
        else
        {
            next_wall.push({nx, y});
        }
    }
}

bool move_wook()
{
    while (!wook.empty())
    {
        int x = wook.front().first;
        int y = wook.front().second;
        wook.pop();

        if (x == 0 && y == 7)
            return true;

        if (map[x][y] == '#')
            continue;

        for (int dir = 0; dir < 9; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8)
                continue;

            if (map[nx][ny] != '.')
                continue;

            next_wook.push({nx, ny});
        }
    }
    return false;
}

void game()
{
    while (true)
    {
        if (move_wook() == true) //탈출 성공할 경우
        {
            cout << 1 << '\n';
            break;
        }
        else
        {
            wook = next_wook;
            move_wall();
            wall = next_wall;
            q_set();

            if (wook.empty())
            {
                cout << 0 << '\n';
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == '#')
                wall.push({i, j});
        }
    }
    wook.push({7, 0});

    game();

    return 0;
}