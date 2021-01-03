#include <iostream>
#define MAX 100000 + 1
using namespace std;

int a[MAX];
int dp[MAX];

int main()
{
    int n, max;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    max = dp[1] = a[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = a[i];

        if (dp[i] < dp[i - 1] + a[i])
            dp[i] = dp[i - 1] + a[i];

        if (max < dp[i])
            max = dp[i];
    }
    printf("%d\n", max);

    return 0;
}