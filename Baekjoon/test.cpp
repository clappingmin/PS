#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int population[11];
bool relation[11][11];
bool visited[11];
bool check[11];
int res = 987654321;

void Calculation()
{
    int A = 0, B = 0;
    for (int i = 1; i <= N; i++)
    {
        if (check[i] == true)
            A += population[i];
        else
            B += population[i];
    }
    int diff = abs(A - B);

    res = min(res, diff);
}

bool Check_connect(vector<int> V, bool b)
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(V[0]);
    visited[V[0]] = true;
    int cnt = 1;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (relation[x][i] == true && check[i] == b && visited[i] == false)
            {
                visited[i] = true;
                cnt += 1;
                q.push(i);
            }
        }
    }
    if (V.size() == cnt)
        return true;

    else
        return false;
}

bool Check()
{
    vector<int> A, B;

    for (int i = 1; i <= N; i++)
    {
        if (check[i])
            A.push_back(i);
        else
            B.push_back(i);
    }

    if (A.size() == 0 || B.size() == 0)
        return false;

    if (!Check_connect(A, true))
        return false;

    if (!Check_connect(B, false))
        return false;

    return true;
}
void Select(int idx, int cnt)
{
    if (cnt > 0)
    {
        if (Check())
            Calculation();
    }

    for (int i = idx; i <= N; i++)
    {
        if (check[i])
            continue;

        check[i] = true;
        Select(i, cnt + 1);
        check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> population[i];

    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;

        for (int j = 0; j < num; j++)
        {
            int x;
            cin >> x;

            relation[i][x] = true;
            relation[x][i] = true;
        }
    }

    Select(1, 0);

    if (res == 987654321)
        cout << -1 << '\n';
    else
        cout << res << '\n';

    return 0;
}
