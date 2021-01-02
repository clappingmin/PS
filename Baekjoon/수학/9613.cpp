#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {
        int n;
        long long res = 0;
        scanf("%d", &n);

        vector<int> v(n);

        for (int i = 1; i <= n; i++)
            scanf("%d", &v[i]);

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                res += gcd(v[i], v[j]);

        cout << res << '\n';

        res = 0;
    }
    return 0;
}