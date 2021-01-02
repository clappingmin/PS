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
    int n, s;

    scanf("%d%d", &n, &s);

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if (a[i] > s)
            a[i] = a[i] - s;
        else
            a[i] = s - a[i];
    }
    for (int i = 1; i < n; i++)
    {
        a[i] = gcd(a[i - 1], a[i]);
    }

    printf("%d\n", a[n - 1]);
    return 0;
}
