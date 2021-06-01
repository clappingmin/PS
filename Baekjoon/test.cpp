#include <iostream>
#include <algorithm>

using namespace std;

int n, k; //물품의 수, 준서가 버틸 수 있는 무게
int w[101], v[101];
int dp[101][100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j]; //담지 않을 경우
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}