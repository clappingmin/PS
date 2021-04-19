#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101], V[101];
int dp[101][100001];

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= W[i])

				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	Solution();

	cout << dp[N][K] << '\n';
}