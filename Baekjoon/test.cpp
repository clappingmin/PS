#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> alpha;

bool check(string res)
{
	int mo = 0, ja = 0;

	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] == 'a' || res[i] == 'i' || res[i] == 'e' || res[i] == 'o' || res[i] == 'u')
			mo++;
		else
			ja++;
	}
	if (mo >= 1 && ja >= 2)
		return true;
	else
		false;
}

void go(int index, string res)
{
	if (res.length() == l)
	{
		if (check(res))
			cout << res << '\n';
		return;
	}
	if (index >= alpha.size())
		return;

	go(index + 1, res + alpha[index]); // 해당 인덱스의 글자가 포함
	go(index + 1, res);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char ch;
		cin >> ch;
		alpha.push_back(ch);
	}

	sort(alpha.begin(), alpha.end());

	go(0, "");

	return 0;
}