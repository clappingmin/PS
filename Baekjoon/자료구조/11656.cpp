#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v;
    string s;

    cin >> s;

    for (int i = 0; i < s.length(); i++)
        v.push_back(s.substr(i, s.length()));

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';

    return 0;
}