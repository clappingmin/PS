#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;
    int k = 2 * n - 1 - 2;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i < n)
        {
            for (int j = 1; j < n - i; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j <= 2 * i; j++)
                cout << '*';
            cout << '\n';
        }
        else
        {
            for (int j = 0; j <= i - n; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j < k; j++)
            {
                cout << '*';
            }
            k -= 2;
            cout << '\n';
        }
    }
    return 0;
}