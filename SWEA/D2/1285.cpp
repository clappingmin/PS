#include <iostream>
#include <math.h>   //abs : 절대값

using namespace std;

int main()
{
    int t, n, input;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        int min = 100001, p = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &input);
            if (min > abs(input))
            {
                min = abs(input);
                p = 1;
            }
            else if (min == abs(input))
                p++;
        }

        printf("#%d %d %d\n", i, min, p);
    }
    return 0;
}