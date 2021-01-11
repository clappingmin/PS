#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;

    cin >> a >> b;

    if (a < b)
    {
        cout << b - a - 1 << '\n';

        for (long long i = a + 1; i < b; i++)
            cout << i << ' ';
    }
    else if (a == b)
    {
        cout << 0;
    }
    else
    {
        cout << a - b - 1 << '\n';

        for (long long i = b + 1; i < a; i++)
            cout << i << ' ';
    }

    return 0;
}