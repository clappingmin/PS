#include <iostream>
#include <queue>

using namespace std;

int N, M, X, Y, K; //지도 크기, 주사위 놓을 좌표, 명령 개수
int map[20][20];

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
queue<int> cmd;
int dice[7];

void RollDice(int c)
{
    int d1 = dice[1];
    int d2 = dice[2];
    int d3 = dice[3];
    int d4 = dice[4];
    int d5 = dice[5];

    int d6 = dice[6];
    if (c == 1) //동쪽으로
    {
        dice[1] = d4;
        dice[3] = d1;
        dice[6] = d3;
        dice[4] = d6;
    }
    else if (c == 2) //서쪽으로
    {
        dice[1] = d3;
        dice[4] = d1;
        dice[6] = d4;
        dice[3] = d6;
    }
    else if (c == 3) //북쪽으로
    {
        dice[1] = d5;
        dice[5] = d6;
        dice[6] = d2;
        dice[2] = d1;
    }
    else if (c == 4) //남쪽으로
    {
        dice[1] = d2;
        dice[5] = d1;
        dice[6] = d5;
        dice[2] = d6;
    }
}

void Solution()
{
    int x = X;
    int y = Y;
    while (!cmd.empty())
    {
        int command = cmd.front();
        cmd.pop();

        int nx = x + dx[command];
        int ny = y + dy[command];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        RollDice(command);

        if (map[nx][ny] != 0)
        {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
        else if (map[nx][ny] == 0)
        {
            map[nx][ny] = dice[6];
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

    cin >> N >> M >> X >> Y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        cmd.push(tmp);
    }

    Solution();

    return 0;
}