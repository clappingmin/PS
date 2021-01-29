#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
int res = 0;

void go(int x, int y, int len)
{
    if (x == r && y == c)
    {
        cout << res << '\n';
        exit(0);
    }
    if (len == 1)
    {
        res++;
        return;
    }
    if (!(x <= r && r < x + len && y <= c && c < y + len))
    {
        res += len * len;
        return;
    }
    go(x, y, len / 2);
    go(x, y + len / 2, len / 2);
    go(x + len / 2, y, len / 2);
    go(x + len / 2, y + len / 2, len / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len;

    cin >> n >> r >> c;

    len = pow(2, n);

    go(0, 0, len);

    return 0;
}