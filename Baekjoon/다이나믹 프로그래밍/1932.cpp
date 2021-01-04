#include <iostream>
#include <algorithm>
#define MAX 500 + 1

using namespace std;

long long a[MAX][MAX];
long long dp[MAX][MAX];

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);

    res = dp[1][1] = a[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else if (i == j)
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            if (res < dp[i][j])
                res = dp[i][j];
        }
    }

    cout << res << '\n';

    return 0;
}