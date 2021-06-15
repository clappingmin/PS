#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> input;
vector<char> use_alpha;
vector<int> value;
int alpha[256];

int check()
{
	int cnt = use_alpha.size();

	for (int i = 0; i < cnt; i++)
	{
		alpha[use_alpha[i]] = value[i];
	}

	int sum = 0;
	for (string s : input)
	{
		int now = 0;
		for (char x : s)
			now = now * 10 + alpha[x];

		sum += now;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		input.push_back(s);

		for (char x : s)
		{
			use_alpha.push_back(x);
		}
	}

	sort(use_alpha.begin(), use_alpha.end());
	use_alpha.erase(unique(use_alpha.begin(), use_alpha.end()), use_alpha.end());

	int cnt = use_alpha.size();

	for (int i = 0; i < cnt; i++)
		value.push_back(9 - i);

	int res = 0;

	do
	{
		res = max(res, check());
	} while (prev_permutation(value.begin(), value.end()));

	cout << res << '\n';
	return 0;
}