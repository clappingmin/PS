#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int w[101], v[101];
int dp[101][100001];

void Solution()
{
    //dp[i][j] = i번째 물건까지 왔고 가방의 제한 무게가 j일때 최고 가치

    for (int i = 1; i <= N; i++)    //물건
    {
        for (int j = 1; j <= K; j++)    //무게
        {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);   //max(담지 않을 경우, 담을 경우)
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    Solution();

    return 0;
}