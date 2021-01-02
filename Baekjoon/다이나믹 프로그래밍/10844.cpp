#include <iostream>

using namespace std;

int dp[100 + 1][10]; //dp[자릿수][마지막 수]

int main()
{
    int n; //자릿수
    long res = 0;

    scanf("%d", &n);

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    dp[1][0] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    for (int i = 0; i <= 9; i++)
        res += dp[n][i];

    cout << res % 1000000000 << '\n';

    return 0;
}