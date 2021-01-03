#include <iostream>
#define MAX 200 + 1
#define mod 1000000000

using namespace std;

long long dp[MAX][MAX];
//dp[k][n] = k번 더해서 n이 나오는 경우의 수

int main()
{
    int N, K;

    scanf("%d%d", &N, &K); // 수, 개수

    for (int i = 0; i <= N; i++)
        dp[1][i] = 1; //1번 더해서 i가 되는 경우는 1번

    for (int k = 2; k <= K; k++)
    {
        for (int n = 0; n <= N; n++)
        {
            for (int l = 0; l <= n; l++)
            {
                dp[k][n] += dp[k - 1][l];
            }
            dp[k][n] %= mod;
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}