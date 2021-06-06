#include <iostream>
#include <queue>
#include <string>
#include <set>
#define ll long long

using namespace std;

char op[] = {'+', '-', '*', '/'};
ll s, t;

ll calculation(ll x, int d)
{
	if (d == 0)
		return (x + x);
	else if (d == 1)
		return (x - x);
	else if (d == 2)
		return (x * x);
	else if (d == 3)
		return (x / x);
}

void solution()
{
	queue<pair<ll, string>> q;
	set<ll> se;
	q.push({s, ""});
	se.insert(s);

	while (!q.empty())
	{
		ll x = q.front().first;
		string str = q.front().second;
		q.pop();

		if (x == t)
		{
			cout << str << '\n';
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			ll nx = calculation(x, dir);

			if (nx < 1)
				continue;
			if (se.find(nx) != se.end()) //이미 있을 경우 continue;
				continue;

			se.insert(nx);
			q.push({nx, str + op[dir]});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> t;

	if (s == t)
		cout << 0 << '\n';
	else
		solution();
	return 0;
}