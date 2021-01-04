#include <iostream>
#include <algorithm>
#define MAX 10000 + 1

using namespace std;

int a[MAX];
int dp[MAX];

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    dp[0] = 0;
    res = dp[1] = a[1];

    if (n >= 2)
    {
        dp[2] = a[1] + a[2];
        res = dp[2];
    }

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(a[i - 1] + dp[i - 3], dp[i - 2]) + a[i];
        dp[i] = max(dp[i], dp[i - 1]);  //현재 잔을 선택하지 않을 경우!!

        if (res < dp[i])
            res = dp[i];
    }
    printf("%d\n", res);

    return 0;
}