#include <iostream>
#include <vector>
#include <algorithm> //max()

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector<int> p(n + 1); //카드 가격
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    dp[0] = p[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] = min(dp[i], dp[i - j] + p[j]);
    }
    printf("%d", dp[n]);

    return 0;
}