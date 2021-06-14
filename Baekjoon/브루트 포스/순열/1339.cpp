#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> input;
vector<char> letters;
vector<int> d;
int alpha[256];

int check()
{
    int cnt = letters.size();

    for (int i = 0; i < cnt; i++)
        alpha[letters[i]] = d[i];

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
            letters.push_back(x);
    }

    sort(letters.begin(), letters.end()); //정렬 후 중복 제거
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    int cnt = letters.size();

    for (int i = 0; i < cnt; i++)
        d.push_back(9 - i);

    int res = 0;

    sort(d.begin(), d.end());
    do
    {
        res = max(res, check());

    } while (next_permutation(d.begin(), d.end()));

    cout << res << '\n';

    return 0;
}