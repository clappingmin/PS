#include <iostream>
#include <cstring>

using namespace std;

int n, cnt = 0;
int arr[1001];
bool check[1001], done[1001];
void dfs(int idx)
{
	check[idx] = true;

	int next = arr[idx];

	if (!check[next])
		dfs(next);

	else if (!done[next])
		cnt++;

	done[next] = true;
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

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));

		cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
				dfs(i);
		}

		cout<<cnt<<'\n';
	}

	return 0;
}