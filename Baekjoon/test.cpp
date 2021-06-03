#include <iostream>
#include <queue>
#include <set>
#include <string>

#define ll long long

using namespace std;

char op[] = {'*', '+', '-', '/'};
ll s, t;

ll Calculation(ll x, char c)
{
	if (c == '*')
		return (x * x);
	else if (c == '+')
		return (x + x);
	else if (c == '-')
		return (x - x);
	else if (c == '/')
		return (x / x);
}

void BFS()
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
			return;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			ll nx = Calculation(x, op[dir]);

			if (nx < 1)
				continue;

			if (se.find(nx) != se.end()) //이미 있을 경우
				continue;

			se.insert(nx);
			q.push({nx, str + op[dir]});
		}
	}
	cout << "-1\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s >> t;

	if (s == t)
		cout << 0 << '\n';
	else
		BFS();

	return 0;
}