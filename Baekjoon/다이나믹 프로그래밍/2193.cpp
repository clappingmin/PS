#include <iostream>

long long dp[91][2]; //dp[자릿수][마지막 자릿수]

using namespace std;

int main()
{
    int n;
    long long res = 0;

    scanf("%d", &n);

    dp[1][1] = 1;
    dp[2][0] = 1;

    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
            else
                dp[i][j] = dp[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= 1; i++)
        res += dp[n][i];

    cout << res << '\n';

    return 0;
}