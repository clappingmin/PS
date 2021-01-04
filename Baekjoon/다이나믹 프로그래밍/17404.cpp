#include <iostream>
#include <algorithm>
#define MAX 1000 + 1

using namespace std;

int a[MAX][3]; //0:빨강, 1:초록, 2:파랑
int dp[MAX][3];

int main()
{
    int n, res = 1000 * 1000;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < 3; i++) //첫번째 집 i번색으로 고정
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                dp[1][j] = a[1][j];
            else
                dp[1][j] = 1000 * 1000 + 1;
        }

        for (int j = 2; j <= n; j++)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + a[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + a[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + a[j][2];
        }
        
        for (int j = 0; j < 3; j++) //n번째 집의 색
        {
            if (i == j)
                continue;
            res = min(res, dp[n][j]);
        }
    }

    printf("%d\n", res);

    return 0;
}