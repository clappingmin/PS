#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int na = 0, nb = 0, nc = 0;

    cin >> t;

    if (t >= 300)
    {
        na = t / 300;
        t %= 300;
    }
    if (t >= 60)
    {
        nb = t / 60;
        t %= 60;
    }
    if (t >= 10)
    {
        nc = t / 10;
        t %= 10;
    }

    if (t != 0)
        cout << -1 << '\n';
    else
        cout << na << " " << nb << " " << nc << '\n';
    return 0;
}