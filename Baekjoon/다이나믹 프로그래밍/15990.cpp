#include <iostream>

using namespace std;

long long dp[100000 + 1][3 + 1];

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {
        int n;

        scanf("%d", &n);

        dp[0][1] = dp[0][2] = dp[0][3] = 0;
        dp[1][1] = dp[2][2] = dp[3][3] = 1;
        dp[1][2] = dp[1][3] = dp[2][1] = dp[2][3] = 0;
        dp[3][1] = dp[3][2] = 1;

        for (int i = 4; i <= n; i++)
        {
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
            dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
            dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
        }

        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
    }
}