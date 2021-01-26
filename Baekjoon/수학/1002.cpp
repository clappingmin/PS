#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, i, x1, y1, x2, y2, r1, r2;

    double d = 0;

    cin >> t;

    while (t--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

        if (r1 + r2 < d)
            cout << 0 << '\n';
        else if (abs(r1 - r2) > d)
            cout << 0 << '\n';
        else if (d == 0 && r1 == r2)
            cout << -1 << '\n';
        else if (d == (r1 + r2))
            cout << 1 << '\n';
        else if (d == abs(r1 - r2))
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}