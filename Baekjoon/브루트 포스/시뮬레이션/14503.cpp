#include<iostream>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int N, M;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
pair<pair<int, int>, int> Robot;
 
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
 
void Input()
{
    cin >> N >> M;
    cin >> Robot.first.first >> Robot.first.second >> Robot.second;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }                                                         
    }
}                         
 
int Turn_Direction(int d)
{
    if (d == 0) return 3;
    else if (d == 1) return 0;
    else if (d == 2) return 1;
    else if (d == 3) return 2;
}
 
void Solution()
{
    int x = Robot.first.first;
    int y = Robot.first.second;
    int d = Robot.second;
    int Room = 0;
    MAP[x][y] = 2;
    Room++;
 
    int nx, ny, nd;
 
    while (1)
    {
        int Tmp_d = d;
        bool Can_Clean = false;
        int CanNotClean = 0;
        for (int i = 0; i < 4; i++)        // 왼쪽방향으로부터 4방향 차례대로 탐색
        {
            nd = Turn_Direction(d);
            nx = x + dx[nd];
            ny = y + dy[nd];
            
            if (MAP[nx][ny] == 0)
            {
                Can_Clean = true;
                break;
            }
            else if (MAP[nx][ny] == 1 || MAP[nx][ny] == 2 || (nx < 0 || ny <0 || nx >=N || ny >=M))
            {
                d = nd;
                CanNotClean++;
            }
        }
 
        if (Can_Clean == true)
        {
            MAP[nx][ny] = 2;
            Room++;
            d = nd;
        }
 
        if (CanNotClean == 4)
        {
            nx = x - dx[Tmp_d];
            ny = y - dy[Tmp_d];
            d = Tmp_d;
            if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || MAP[nx][ny] == 1 )
            {
                break;
            }
        }
        x = nx;
        y = ny;
    }
    cout << Room << endl;
}                                                                                       
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
 
    return 0;
}
 
