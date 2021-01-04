#include <iostream>
#define MAX 1000 + 1

int a[MAX];
int dp[MAX];

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    res = dp[1] = a[1];

    for (int i = 2; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (max < dp[j])
                    max = dp[j];
            }
        }
        dp[i] = max + a[i];

        if (res < dp[i])
            res = dp[i];
    }
    printf("%d", res);
    return 0;
}