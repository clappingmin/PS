#include <iostream>

using namespace std;

int main()
{
    int E, S, M;
    int e = 1, s = 1, m = 1, year = 1;

    scanf("%d%d%d", &E, &S, &M);

    while (true)
    {
        if (e == E && s == S && m == M)
        {
            printf("%d\n", year);
            return 0;
        }

        e++;
        s++;
        m++;

        if (e > 15)
            e -= 15;
        if (s > 28)
            s -= 28;
        if (m > 19)
            m -= 19;

        year++;
    }

    return 0;
}