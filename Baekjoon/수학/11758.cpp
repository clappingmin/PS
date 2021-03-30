#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int a = x1 * y2 + x2 * y3 + x3 * y1;
    int b = y1 * x2 + y2 * x3 + y3 * x1;

    if (a - b > 0) //반시계 방향
        cout << 1 << '\n';
    else if (a == b) //직선
        cout << 0 << '\n';
    else //시계
        cout << -1 << '\n';

    return 0;
}