#include <iostream>

using namespace std;

int dp[201];
int c[201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, max;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    dp[0] = 0;
    dp[1] = max = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (c[i] > c[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;

                if (dp[i] > max)
                    max = dp[i];
            }
        }
    }

    cout << n - max;

    return 0;
}