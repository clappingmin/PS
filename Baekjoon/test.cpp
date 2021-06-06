#include <iostream>
#include <algorithm>

using namespace std;

int n, k;			//물품 수, 버틸 수 있는 무게
int w[101], v[101]; //무게, 물건 가치
int dp[101][100001];

void solution()
{
	for (int i = 1; i <= n; i++) //물건
	{
		for (int j = 1; j <= k; j++) //넣을 수 있는 무게
		{
			if (j - w[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	solution();

	cout << dp[n][k];

	return 0;
}