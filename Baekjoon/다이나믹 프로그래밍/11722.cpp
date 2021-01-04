#include <iostream>
#define MAX 1000 + 1

using namespace std;

int a[MAX];
int dp[MAX];

int main()
{
    int n, res = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] < a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (res < dp[i])
            res = dp[i];
    }

    printf("%d", res);

    return 0;
}