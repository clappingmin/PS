#include <iostream>
#define MAX 30 + 1

int dp[MAX] = {1, 0, 3};

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 3 * dp[i - 2];

        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}