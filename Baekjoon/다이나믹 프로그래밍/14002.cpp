#include <iostream>
#include <vector>
#include <algorithm>
#define max 1000 + 1

using namespace std;

int a[max];
int dp[max];
int v[max];
vector<int> lis;

void go(int index)
{
    if (index == 0)
    {
        return;
    }
    lis.push_back(a[index]);
    go(v[index]);
}

int main()
{
    int n, res = 1;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    dp[1] = 1;
    v[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1;

        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                v[i] = j;
            }
        }
        if (res < dp[i])
            res = dp[i];
    }
    printf("%d\n", res);

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == res)
        {
            lis.push_back(a[i]);
            go(v[i]);
            break;
        }
    }

    sort(lis.begin(), lis.end());

    for (int i = 0; i < lis.size(); i++){
        printf("%d ", lis[i]);
    }

    return 0;
}