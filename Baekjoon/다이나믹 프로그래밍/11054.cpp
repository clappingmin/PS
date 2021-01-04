#include <iostream>
#define MAX 1000 + 1

int a[MAX];
int dp1[MAX]; //증가하는 수열
int dp2[MAX]; //감소하는 수열

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    dp1[1] = dp2[1] = 1;

    //증가하는 수열
    for (int i = 2; i <= n; i++)
    {
        dp1[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i] && dp1[i] < dp1[j] + 1)
                dp1[i] = dp1[j] + 1;
        }
    }

    //감소하는 수열
    for (int i = 2; i <= n; i++)
    {
        dp2[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] > a[i] && dp1[i] < dp1[j] + 1)
                dp1[i] = dp1[j] + 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (res < dp1[i] + dp2[i] - 1) //i번째가 중복되니 -1
            res = dp1[i] + dp2[i] - 1;
    }

    printf("%d\n", res);

    return 0;
}