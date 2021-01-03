#include <iostream>
#define MAX 100000 + 1
#define mod 9901

using namespace std;

long long dp[MAX][3];

int main()
{
    int n;
    scanf("%d", &n);
    /*
    dp[n][0] : n번째 줄에 아무것도 배치하지 않음
    dp[n][1] : n번째 줄 오른쪽에 동물을 배치
    dp[n][2] : n번째 줄 왼쪽에 동물을 배치
    */

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;

    return 0;
}