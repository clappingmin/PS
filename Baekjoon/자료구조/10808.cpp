#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	string s;
	vector<char> v;
	int alp[26];

	cin >> s;

	for (int i = 0; i < 26; i++)
		alp[i] = 0;

	for (int i = 0; i < s.length(); i++) {
		int n = s.at(i) - 97;
		alp[n]++;	
	}

	for (int i = 0; i < 26; i++)
		cout << alp[i] << " ";
	cout << '\n';
	
	return 0;
}