#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	s.push_back("a");
		s.push_back("a");
			s.push_back("a");
	s.push_back("b");
	s.push_back("a");
	s.push_back("c");
	s.push_back("b");
	s.push_back("a");
	s.push_back("b");

	s.erase(unique(s.begin(), s.end()), s.end());

	for (int i = 0; i < s.size(); i++)
		cout << s[i] << "\n";

	return 0;
}