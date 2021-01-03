#include <iostream>
#include <algorithm>
#define mod 1000000009
#define MAX 1000000 + 1

using namespace std;

long long dp[MAX];

int main()
{
    int t;

    scanf("%d", &t);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    while (t--)
    {
        int n;

        scanf("%d", &n);

        for (int i = 4; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;

        cout << dp[n] % mod << "\n";
    }

    return 0;
}
