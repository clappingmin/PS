#include <iostream>
#include <string>
using namespace std;

int t, n, bit;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        s.clear();
        cin >> s;

        if (s == "add")
        {
            cin >> n;
            bit |= (1 << n);
        }
        else if (s == "remove")
        {
            cin >> n;
            bit &= ~(1 << n);
        }
        else if (s == "check")
        {
            cin >> n;
            if (bit & (1 << n))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (s == "toggle")
        {
            cin >> n;
            bit ^= (1 << n);
        }
        else if (s == "all")
        {
            bit = (1 << 21) - 1;
        }
        else if (s == "empty")
        {
            bit = 0;
        }
    }

    return 0;
}