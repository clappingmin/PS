#include <iostream>
#include <cstring>

using namespace std;

int n, cnt;
int arr[100001];
bool done[100001], check[100001];

void dfs(int idx)
{
	check[idx] = true;

	int next = arr[idx];

	if (!check[next])
		dfs(next);

	else if (!done[next])
	{
		for (int i = next; i != idx; i = arr[i])
			cnt++;
		cnt++;
	}
	done[idx] = true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;

	cin >> t;

	while (t--)
	{
		cin >> n;

		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		cnt = 0;

		for (int i = 1; i <= n; i++)
			if (!check[i])
				dfs(i);

		cout << n - cnt << '\n';
	}

	return 0;
}