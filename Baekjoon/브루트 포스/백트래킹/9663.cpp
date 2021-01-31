#include <iostream>
#include <cmath>

using namespace std;

int n;
int col[15];
int res = 0;

bool check(int i)
{
    for (int j = 0; j < i; j++)
    {
        if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
            return false;
    }
    return true;
}
void go(int i)
{
    if (i == n)
        res += 1;
    else
    {
        for (int j = 0; j < n; j++)
        {
            col[i] = j;
            if (check(i))
                go(i + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    go(0);

    cout << res << '\n';

    return 0;
}