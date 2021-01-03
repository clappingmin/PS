#include <iostream>
#include <algorithm>
#define MAX 100000 + 1

using namespace std;

int a[2][MAX]; // 2*n 스티커
int dp[2][MAX];

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;

        scanf("%d", &n);

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);

        dp[0][1] = a[0][1]; //윗줄
        dp[1][1] = a[1][1]; //아래줄

        dp[0][2] = a[0][2]+a[1][1];
        dp[1][2] = a[1][2]+a[0][1];

        for (int i = 3; i <= n; i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + a[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + a[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
    return 0;
}