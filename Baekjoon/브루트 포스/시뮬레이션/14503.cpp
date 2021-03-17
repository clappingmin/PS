#include <iostream>

using namespace std;

int n, m; //map 크기
int map[51][51];

pair<pair<int, int>, int> Robot; //로봇 초기 위치, 방향

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Turn_direction(int d)
{
    if (d == 0)
        return 3;
    else if (d == 1)
        return 0;
    else if (d == 2)
        return 1;
    else if (d == 3)
        return 2;
}

void Solution()
{
    int x = Robot.first.first;
    int y = Robot.first.second;
    int d = Robot.second;
    int room = 0; //청소한 방의 개수

    map[x][y] = 2; //시작지점 방 청소
    room++;

    int nx, ny, nd; //다음 청소 위치, 방향

    while (1)
    {
        int tmp_d = d;
        bool can_clean = false;
        int cannotclean = 0;

        for (int i = 0; i < 4; i++)
        {
            nd = Turn_direction(d);
            nx = x + dx[nd];
            ny = y + dy[nd];

            if (map[nx][ny] == 0) //청소를 할 수 있는 경우
            {
                can_clean = true;
                break;
            }
            else if (map[nx][ny] == 1 || map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                //벽이거나 이미 청소를 했거나 범위를 벗어난 경우
                d = nd;
                cannotclean++;
            }
        }
        if (can_clean == true)
        {
            map[nx][ny] = 2;
            room++;
            d = nd;
        }
        if (cannotclean == 4)
        {
            nx = x - dx[tmp_d];
            ny = y - dy[tmp_d]; //후진
            d = tmp_d;

            if (map[nx][ny] == 1 || nx < 0 || ny < 0 || nx >= n || ny >= m)
            { //후진할 공간이 벽이거나 범위를 벗어난 경우
                break;
            }
        }
        x = nx;
        y = ny;
    }
    cout << room << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> Robot.first.first >> Robot.first.second >> Robot.second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    Solution();

    return 0;
}
