#include <iostream>
#include <climits>

using namespace std;

int n;
int t[16]; //상담일
int p[16]; //금액
int res = INT_MIN;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void dfs(int day, int pay)
{
    if (day == n + 1)
    {
        res = max(res, pay);
        return;
    }

    if (day > n + 1)
        return;

    dfs(day + t[day], pay + p[day]);
    dfs(day + 1, pay);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        cin >> p[i];
    }

    dfs(1, 0);

    cout << res << '\n';

    return 0;
}