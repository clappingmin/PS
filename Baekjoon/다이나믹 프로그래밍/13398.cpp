#include <iostream>
#define MAX 100000 + 1

int a[MAX];
int dp[MAX];  // i에서 끝나는 연속합
int dp2[MAX]; // i에서 시작하는 연속합

int main()
{
    int n, max = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    max = dp[1] = a[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = a[i];

        if (dp[i] < dp[i - 1] + a[i])
            dp[i] = dp[i - 1] + a[i];

        if (max < dp[i])
            max = dp[i];
    }

    dp2[n] = a[n];

    for (int i = n - 1; i >= 1; i--)
    {
        dp2[i] = a[i];
        if (dp2[i] < dp2[i + 1] + a[i])
            dp2[i] = dp2[i + 1] + a[i];
    }

    for (int i = 2; i < n; i++)
    {
        if (max < dp[i - 1] + dp2[i + 1])
            max = dp[i - 1] + dp2[i + 1];
    }

    printf("%d\n",max);

    return 0;
}