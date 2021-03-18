#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define MAX 10 + 1

using namespace std;

int N;
int person[MAX]; //인구수 저장
bool connected[MAX][MAX];
bool selected[MAX];
bool visited[MAX];
int res = 987654321;

void Calculation()
{
    int sum_a = 0, sum_b = 0, diff;

    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
            sum_a += person[i];
        else
            sum_b += person[i];
    }
    diff = abs(sum_a - sum_b);
    res = min(res, diff);
}

bool Check_connection(vector<int> v, bool t)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v.front());
    visited[v.front()] = true;
    int cnt = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (connected[x][i] == true && selected[i] == t && visited[i] == false)
            {
                //이어져있고, 같은 선거구이며, 방문한 적이 없는 경우를 확인
                visited[i] = true;
                cnt += 1;
                q.push(i);
            }
        }
    }
    if (v.size() == cnt)
        return true;

    return false;
}

bool Check()
{
    vector<int> A, B;

    for (int i = 1; i <= N; i++)
    {
        if (selected[i] == true)
            A.push_back(i);
        else
            B.push_back(i);
    }

    //조건 1.선거구는 지역을 최소 1개 이상 갖는다.
    if (A.size() == 0 || B.size() == 0)
        return false;

    //조건 2. 같은 선거구의 지역들은 서로 이어져 있다.
    if (Check_connection(A, true) == false)
        return false;

    if (Check_connection(B, false) == false)
        return false;

    return true;
}

void DFS(int index, int cnt) //1.선거구 조합
{
    if (cnt >= 1)
    {
        if (Check()) //2.조건이 맞는지 확인한다.
        {
            Calculation(); //3. 조건이 맞을 경우 인구수 차이 계산
        }
    }

    for (int i = index; i <= N; i++)
    {
        if (selected[i] == true)
            continue;

        selected[i] = true;
        DFS(i, cnt + 1);
        selected[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> person[i];

    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++)
        {
            int c;
            cin >> c;

            connected[i][c] = true;
            connected[c][i] = true;
        }
    }

    DFS(1, 0); //1. 선거구 조합

    if (res == 987654321)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}