#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[12][6];
bool visited[12][6];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int res = 0;
queue<pair<int, int>> pop;

void find_puyo(int i, int j)
{
    queue<pair<int, int>> puyo; //뿌요들 좌표 저장할 큐
    queue<pair<int, int>> q;    //같은 색상의 뿌요를 찾을때 사용할 큐
    visited[i][j] = true;
    puyo.push({i, j});
    q.push({i, j});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                continue;

            if (map[x][y] != map[nx][ny] || visited[nx][ny])
                continue;

            q.push({nx, ny});
            puyo.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    if (puyo.size() >= 4) //4개 이상이면 좌표를 따로 저장
    {
        int cnt = puyo.size();
        for (int i = 0; i < cnt; i++)
        {
            pop.push(puyo.front());
            puyo.pop();
        }
    }
}

void pop_puyo(int x, int y)
{
    for (int i = x - 1; i >= 0; i--)
    {
        map[i + 1][y] = map[i][y];
    }
    map[0][y] = '.';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            cin >> map[i][j];

    while (true)
    {
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < 12; i++) // 1. 4개 이상인 뿌요는 찾아서 좌표 저장
        {
            for (int j = 0; j < 6; j++)
            {
                if (map[i][j] != '.' && !visited[i][j])
                {
                    find_puyo(i, j);
                }
            }
        }

        if (pop.size() == 0) //터트릴 뿌요가 없으면 끝
            break;

        int cnt = pop.size();

        for (int i = 0; i < cnt; i++)
        {
            //2. 찾아놓은 4개 이상 뿌요 터트리고 줄 정리
            int x = pop.front().first;
            int y = pop.front().second;

            pop_puyo(x, y);

            pop.pop();
        }

        res += 1;
    }

    cout << res << '\n';

    return 0;
}