#include <iostream>

using namespace std;

int n, res = 0;
int t[16]; //상담 기간
int p[16]; //받는 금액

void go(int day, int sum)
{
    if (day == n + 1) //퇴사하는 날
    {
        if (res < sum)
            res = sum;
        return;
    }
    if (day > n + 1)
        return;
    go(day + t[day], sum + p[day]); //당일날 상담 진행
    go(day + 1, sum);               //당일날 상담 안함
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    go(1, 0);
    cout << res << "\n";

    return 0;
}