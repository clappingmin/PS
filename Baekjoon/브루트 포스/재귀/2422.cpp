#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool not_good[201][201];
int res = 0;
bool check[201];
vector<int> v;

bool Check_ice()
{
    if (not_good[v[0]][v[1]] || not_good[v[1]][v[2]] || not_good[v[2]][v[0]])
        return false;
    else
        return true;
}

void go(int idx, int cnt)
{
    if (cnt == 3)
    {
        if (Check_ice())
            res++;

        return;
    }

    for (int i = idx; i <= N; i++)
    {
        if (check[i])
            continue;

        check[i] = true;
        v.push_back(i);
        go(i, cnt + 1);
        v.pop_back();
        check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        not_good[x][y] = true;
        not_good[y][x] = true;
    }

    go(1, 0);

    cout<<res<<'\n';

    return 0;
}