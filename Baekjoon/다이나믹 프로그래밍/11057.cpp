#include <iostream>
#define MAX 1000 + 1
#define mod 10007

using namespace std;

long long dp[MAX][10];
int main()
{
    int n, res = 0;

    scanf("%d", &n);

    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k] % mod;
            }
        }
    }
    for (int i = 0; i <= 9; i++)
        res += dp[n][i];

    cout << res % mod << "\n";

    return 0;
}