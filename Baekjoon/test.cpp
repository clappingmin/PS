#include <iostream>
#include <queue>
#include <string>
#include <set>

using namespace std;

long long S, T;
char op[] = {'*', '+', '-', '/'};

long long Calculation(long long x, char c)
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
	queue<pair<long long, string>> q;
	set<long long> se; //중복 방지를 위해서 사용
	q.push({S, ""});
	se.insert(S);

	while (!q.empty())
	{
		long long x = q.front().first;
		string s = q.front().second;
		q.pop();

		if (x == T)
		{
			cout << s << '\n';
			return;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			long long nx = Calculation(x, op[dir]);

			if (nx < 1)
				continue;

			if (se.find(nx) != se.end()) //이미 있을 경우
				continue;

			se.insert(nx);
			q.push({nx, s + op[dir]});
		}
	}
	cout << "-1\n"
		 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> S >> T;

	if (S == T)
		cout << 0 << '\n';
	else
		BFS();

	return 0;
}