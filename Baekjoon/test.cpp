#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int op[4];
int num[11];
int min_res = INT_MAX;
int max_res = INT_MIN;

void dfs(int idx, int add, int sub, int mul, int div, int sum)
{
	if (idx == n - 1)
	{
		min_res = min(min_res, sum);
		max_res = max(max_res, sum);
		return;
	}

	if (add != 0)
		dfs(idx + 1, add - 1, sub, mul, div, sum + num[idx + 1]);
	if (sub != 0)
		dfs(idx + 1, add, sub - 1, mul, div, sum - num[idx + 1]);
	if (mul != 0)
		dfs(idx + 1, add, sub, mul - 1, div, sum * num[idx + 1]);
	if (div != 0)
	{
		if (sum < 0)
		{
			sum = abs(sum) / num[idx + 1];
			sum *= -1;
			dfs(idx + 1, add, sub, mul, div - 1, sum);
		}
		else
			dfs(idx + 1, add, sub, mul, div - 1, sum / num[idx + 1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	dfs(0, op[0], op[1], op[2], op[3], num[0]);

	cout << max_res << '\n'
		 << min_res << '\n';
	return 0;
}