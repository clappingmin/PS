#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k = 3;

    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i < n)
        {
            for (int j = 0; j < i; j++)
            {
                cout << ' ';
            }
            for (int j = i + 1; j <= 2 * n - 1 - i; j++)
            {
                cout << '*';
            }
        }
        else
        {
            for (int j = 2; j <= n - (i - n) - 1; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j < k; j++)
            {
                cout << '*';
            }
            k += 2;
        }
        cout << '\n';
    }

    return 0;
}