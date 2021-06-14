#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> num;
vector<int> sign;

int calc()
{
    int res = num[0];
    for (int i = 0; i < sign.size(); i++)
    {
        int d = sign[i];

        if (d == 0)
            res += num[i + 1];
        else if (d == 1)
            res -= num[i + 1];
        else if (d == 2)
            res *= num[i + 1];
        else if (d == 3)
            res /= num[i + 1];
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        num.push_back(x);
    }
    for (int i = 0; i < 4; i++) // 0: +, 1: -, 2: *, 3: /
    {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++)
            sign.push_back(i);
    }

    sort(sign.begin(), sign.end());

    int min_res = 987654321;
    int max_res = -987654321;
    do
    {
        int res = calc();

        min_res = min(min_res, res);
        max_res = max(max_res, res);

    } while (next_permutation(sign.begin(), sign.end()));

    cout << max_res << '\n'
         << min_res << '\n';

    return 0;
}