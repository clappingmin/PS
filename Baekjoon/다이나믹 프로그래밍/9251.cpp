#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char a[1001], b[1001];
int dp[1001][1001];

void lcs()
{
    int a_size = strlen(a);
    int b_size = strlen(b);

    for (int i = 1; i <= a_size; i++)
    {
        for (int j = 1; j <= b_size; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[a_size][b_size] << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    lcs();

    return 0;
}