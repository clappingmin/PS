#include <iostream>

using namespace std;

int main()
{

    int t, p, q, r, s, w;
    int a, b;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d%d%d%d", &p, &q, &r, &s, &w);
        a = p * w;

        if (w <= r)
            b = q;
        else
            b = q + (w - r) * s;

        if (a < b)
            printf("#%d %d\n", i, a);
        else
            printf("#%d %d\n", i, b);
    }
    return 0;
}