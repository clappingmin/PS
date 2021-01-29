#include <iostream>
#include <string>

using namespace std;

int n;
int map[64][64];
string res = "";
void go(int x, int y, int n)
{
    int temp = 0;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (map[i][j])
                temp++;
        }
    }
    if (!temp)
        res += '0';
    else if (temp == n * n)
        res += '1';
    else
    {
        res += '(';
        go(x, y, n / 2);
        go(x, y + n / 2, n / 2);
        go(x + n / 2, y, n / 2);
        go(x + n / 2, y + n / 2, n / 2);
        res += ')';
    }

    return;
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
        for (int j = 0; j < n; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    go(0, 0, n);

    cout << res << '\n';

    return 0;
}