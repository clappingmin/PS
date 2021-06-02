#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;
vector<ll> tree;

bool possible(ll mid)
{
	ll tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] > mid)
			tmp += (tree[i] - mid);
	}

	if (tmp >= m)
		return true;
	else
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	ll high = 0, low = 1, res = 0;

	for (int i = 0; i < n; i++)
	{
		ll height;
		cin >> height;

		tree.push_back(height);
		high = max(high, height);
	}

	while (low <= high)
	{
		ll mid = (high + low) / 2;

		if (possible(mid))
		{
			if (res < mid)
				res = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout<<res<<'\n';

	return 0;
}