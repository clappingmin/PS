#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string s)
{
    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
            res += (s[i] - '0');
    }
    return res;
}

bool cmp(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();

    else
    {
        int sum_a = sum(a);
        int sum_b = sum(b);

        if (sum_a != sum_b)
            return sum_a < sum_b;

        else
            return a < b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << v[i] << '\n';

    return 0;
}