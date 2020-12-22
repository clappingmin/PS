#include <iostream>

using namespace std;

int main()
{
    int t;
    int h1, m1, h2, m2;
    int resh, resm;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d%d%d", &h1, &m1, &h2, &m2);

        resh = h1 + h2;
        resm = m1 + m2;

        if (resh > 12)
            resh -= 12;

        if (resm >= 60)
        {
            resh += (resm / 60);
            resm = (resm % 60);
        }
        printf("#%d %d %d\n", i, resh, resm);
    }
    return 0;
}