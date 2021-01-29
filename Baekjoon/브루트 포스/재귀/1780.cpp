#include <iostream>

using namespace std;

int map[2187][2187];
int n0 = 0, n1 = 0, n2 = 0;

void go(int x, int y, int n)
{
    int tmp0 = 0, tmp1 = 0, tmp2 = 0;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (map[i][j] == 0)
                tmp0++;
            else if (map[i][j] == 1)
                tmp1++;
            else if (map[i][j] == -1)
                tmp2++;
        }
    }
    if (tmp0 == n * n)
        n0++;
    else if (tmp1 == n * n)
        n1++;
    else if (tmp2 == n * n)
        n2++;
    else
    {
        go(x, y, n / 3);
        go(x, y + n / 3, n / 3);
        go(x, y + 2 * n / 3, n / 3);

        go(x + n / 3, y, n / 3);
        go(x + n / 3, y + n / 3, n / 3);
        go(x + n / 3, y + 2 * n / 3, n / 3);

        go(x + 2 * n / 3, y, n / 3);
        go(x + 2 * n / 3, y + n / 3, n / 3);
        go(x + 2 * n / 3, y + 2 * n / 3, n / 3);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    go(0, 0, n);

    cout<<n2<<'\n'<<n0<<'\n'<<n1;

    return 0;
}