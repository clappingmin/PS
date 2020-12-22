#include <iostream>
using namespace std;

int main()
{
    int t, n;
    int a = 0, b = 0, c = 0, d = 0, e = 0; //2,3,5,7,11
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);

        while (n % 2 == 0)
        {
            n /= 2;
            a++;
        }
        while (n % 3 == 0)
        {
            n /= 3;
            b++;
        }
        while (n % 5 == 0)
        {
            n /= 5;
            c++;
        }
        while (n % 7 == 0)
        {
            n /= 7;
            d++;
        }
        while (n % 11 == 0)
        {
            n /= 11;
            e++;
        }
        printf("#%d %d %d %d %d %d\n", i, a, b, c, d, e);
        
        a = 0, b = 0, c = 0, d = 0, e = 0;
    }
    return 0;
}