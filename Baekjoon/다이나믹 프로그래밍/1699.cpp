#include <iostream>
#include <algorithm>
#define MAX 100000 + 1

using namespace std;

int dp[MAX];

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i; // 제일 큰 방법으로 초기화   ex)3=1+1+1 => i일 경우 항이 i개

        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    printf("%d", dp[n]);

    return 0;
}