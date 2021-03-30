#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<deque<int>> dq(4);
int K;

int Count()
{
    int res = 0;

    if (dq[0][0] == 1)
        res += 1;
    if (dq[1][0] == 1)
        res += 2;
    if (dq[2][0] == 1)
        res += 4;
    if (dq[3][0] == 1)
        res += 8;

    return res;
}

void spin(int num, int dir)
{
    if (dir == 1) //시계 방향일 경우
    {
        int temp = dq[num].back();
        dq[num].pop_back();
        dq[num].push_front(temp);
    }
    else if (dir == -1) //반시계 방향일 경우
    {
        int temp = dq[num].front();
        dq[num].pop_front();
        dq[num].push_back(temp);
    }
}

void Solution(int num, int dir)
{
    // o: 돌리는 톱니바퀴
    // x: 돌리지 않는 톱니바퀴

    if (num == 0)
    {
        if (dq[0][2] == dq[1][6]) //oxxx
            spin(0, dir);

        else if (dq[0][2] != dq[1][6] && dq[1][2] == dq[2][6]) //ooxx
        {
            spin(0, dir);
            spin(1, -dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] == dq[3][6]) //ooox
        {
            spin(0, dir);
            spin(1, -dir);
            spin(2, dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] != dq[3][6]) //oooo
        {
            spin(0, dir);
            spin(1, -dir);
            spin(2, dir);
            spin(3, -dir);
        }
    }
    else if (num == 1)
    {
        if (dq[0][2] == dq[1][6] && dq[1][2] == dq[2][6]) //xoxx
            spin(1, dir);
        else if (dq[0][2] != dq[1][6] && dq[1][2] == dq[2][6]) //ooxx
        {
            spin(0, -dir);
            spin(1, dir);
        }
        else if (dq[0][2] == dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] == dq[3][6]) //xoox
        {
            spin(1, dir);
            spin(2, -dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] == dq[3][6]) //ooox
        {
            spin(0, -dir);
            spin(1, dir);
            spin(2, -dir);
        }
        else if (dq[0][2] == dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] != dq[3][6]) //xooo
        {
            spin(1, dir);
            spin(2, -dir);
            spin(3, dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] != dq[3][6]) //oooo
        {
            spin(0, -dir);
            spin(1, dir);
            spin(2, -dir);
            spin(3, dir);
        }
    }
    else if (num == 2)
    {
        if (dq[1][2] == dq[2][6] && dq[2][2] == dq[3][6]) //xxox
            spin(2, dir);
        else if (dq[0][2] == dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] == dq[3][6]) //xoox
        {
            spin(1, -dir);
            spin(2, dir);
        }
        else if (dq[1][2] == dq[2][6] && dq[2][2] != dq[3][6]) //xxoo
        {
            spin(2, dir);
            spin(3, -dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] == dq[3][6]) //ooox
        {
            spin(0, dir);
            spin(1, -dir);
            spin(2, dir);
        }
        else if (dq[0][2] == dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] != dq[3][6]) //xooo
        {
            spin(1, -dir);
            spin(2, dir);
            spin(3, -dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] != dq[3][6]) //xxxx
        {
            spin(0, dir);
            spin(1, -dir);
            spin(2, dir);
            spin(3, -dir);
        }
    }
    else if (num == 3)
    {
        if (dq[3][6] == dq[2][2]) //xxxo
            spin(3, dir);
        else if (dq[3][6] != dq[2][2] && dq[2][6] == dq[1][2]) //xxoo
        {
            spin(2, -dir);
            spin(3, dir);
        }
        else if (dq[3][6] != dq[2][2] && dq[2][6] != dq[1][2] && dq[1][6] == dq[0][2]) //xooo
        {
            spin(3, dir);
            spin(2, -dir);
            spin(1, dir);
        }
        else if (dq[0][2] != dq[1][6] && dq[1][2] != dq[2][6] && dq[2][2] != dq[3][6]) //oooo
        {
            spin(0, -dir);
            spin(1, dir);
            spin(2, -dir);
            spin(3, dir);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++)
    {
        string s = "";
        cin >> s;

        for (int j = 0; j < 8; j++)
        {
            dq[i].push_back(s[j] - '0');
        }
    }

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int num, dir;
        cin >> num >> dir;

        Solution(num - 1, dir);
    }

    cout << Count() << '\n';

    return 0;
}