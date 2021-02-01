#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int n1 = w - x;
    int n2 = h - y;

    cout << min(min(min(n1, n2), x), y);

    return 0;
}