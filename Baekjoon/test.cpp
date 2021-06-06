#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m; //나무 수, 가져갈 나무 길이
vector<ll> tree;
ll high, low, mid;
ll res = 0;

bool check(ll h)
{
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		if (tree[i] > h)
			temp += (tree[i] - h);
	}
	if (temp >= m)
		return true;

	return false;
}

void solution()
{
	low = 1;

	while (low <= high)
	{
		mid = (high + low) / 2;

		if (check(mid))
		{
			low = mid + 1;

			res = max(res, mid);
		}
		else
			high = mid - 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		ll input;
		cin >> input;
		tree.push_back(input);
		high = max(high, input);
	}

	solution();

	cout << res << '\n';

	return 0;
}