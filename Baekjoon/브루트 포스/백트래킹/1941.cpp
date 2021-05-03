#include <iostream>
#include <cstring>
#include <string>
#include <queue>

#define endl "\n"
using namespace std;

int MAP[5][5], Answer;
bool Select[25];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input()
{
    for (int i = 0; i < 5; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            if (Inp[j] == 'Y')
                MAP[i][j] = 1;
            else if (Inp[j] == 'S')
                MAP[i][j] = 2;
        }
    }
}

bool MoreThanFour() //4명 이상인지
{
    int Cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (Select[i] == true)
        {
            int x = i / 5;
            int y = i % 5;

            if (MAP[x][y] == 2)
                Cnt++;
        }
    }
    if (Cnt >= 4)
        return true;
    else
        return false;
}

bool Adjacency()    //서로 연결되어 있는지
{
    queue<pair<int, int>> Q;
    bool Check_Select[5][5];
    bool Queue_Select[5][5];
    bool Check_Answer = false;

    memset(Queue_Select, false, sizeof(Queue_Select));
    memset(Check_Select, false, sizeof(Check_Select));

    int Tmp = 0;
    for (int i = 0; i < 25; i++)
    {
        if (Select[i] == true)
        {
            int x = i / 5;
            int y = i % 5;
            Check_Select[x][y] = true;

            if (Tmp == 0)
            {
                Q.push(make_pair(x, y));
                Queue_Select[x][y] = true;
                Tmp++;
            }
        }
    }

    int Cnt = 1;
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        if (Cnt == 7)
        {
            Check_Answer = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            {
                if (Check_Select[nx][ny] == true && Queue_Select[nx][ny] == false)
                {
                    Queue_Select[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                    Cnt++;
                }
            }
        }
    }

    if (Check_Answer == true)
        return true;
    return false;
}

void DFS(int Idx, int Cnt)  //7명 선택하기
{
    if (Cnt == 7)
    {
        if (MoreThanFour() == true)
        {
            if (Adjacency() == true)
                Answer++;
        }
        return;
    }

    for (int i = Idx; i < 25; i++)
    {
        if (Select[i] == true)
            continue;
        Select[i] = true;
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}

void Solution()
{
    DFS(0, 0);
    cout << Answer << endl;
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
