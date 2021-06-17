#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int t[16], p[16]; //상담일, 금액
int res = INT_MIN;

void go(int day, int sum)
{
    if (day == n + 1)
    {
        res = max(res, sum);
        return;
    }
    if (day > n + 1)
        return;

    go(day + t[day], sum + p[day]);
    go(day + 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    go(1, 0);

    cout<<res<<'\n';

    return 0;
}