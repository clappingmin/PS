#include <iostream>
#include <algorithm>

#define MAX 1000 + 1

using namespace std;

int a[MAX][3];  // 0:R, 1:G, 2:B
int dp[MAX][3]; //[집의 수][마지막 칠한 색]

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < 3; i++)
        dp[1][i] = a[1][i];

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
    }

    printf("%d", min(min(dp[n][0], dp[n][1]), dp[n][2]));

    return 0;
}