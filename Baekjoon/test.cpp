#include <iostream>
#include <cstring>
#define MAX 100000 + 1

using namespace std;

int n;
int student[MAX];
bool check[MAX];
bool done[MAX];
int cnt = 0;

void dfs(int idx)
{
	check[idx] = true;
	int next = student[idx];

	if (!check[next])
		dfs(next);

	else if (!done[next])
	{
		for (int i = next; i != idx; i = student[i])
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
		cnt = 0;
		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));

		for (int i = 1; i <= n; i++)
			cin >> student[i];

		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
				dfs(i);
		}
		cout<<n-cnt<<'\n';
	}

	return 0;
}