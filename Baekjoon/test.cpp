#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<char> letters;
char alpha[256];

int calc(vector<string> &a, vector<int> &d)
{
	int m = letters.size();
	int sum = 0;

	for (int i = 0; i < m; i++)
	{
		alpha[letters[i]] = d[i];
	}

	for (string s : a)
	{
		int now = 0;
		for (char x : s)
		{
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<string> a(n); //단어 저장

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		for (char x : a[i])
			letters.push_back(x);
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end()); //중복제거

	int m = letters.size();

	vector<int> d;

	for (int i = 0; i < m; i++)
	{
		d.push_back(9 - i);
	}

	int res = 0;
	
	do
	{
		int now = calc(a, d);

		res = max(res, now);

	} while (next_permutation(d.begin(), d.end()));

	cout << res << '\n';

	return 0;
}