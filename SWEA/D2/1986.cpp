#include <iostream>

using namespace std;

int main()
{
    int t, n;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j % 2 == 1)
                res += j;
            else
                res -= j;
        }
        printf("#%d %d\n", i, res);
    }

    return 0;
}