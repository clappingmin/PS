#include <iostream>

using namespace std;

int main()
{
    int n, res = 0;

    scanf("%d", &n);

    if (5 <= n)
        res += (n / 5);

    if (25 <= n)
        res += (n / 25);

    if (125 <= n)
        res += (n / 125);

    printf("%d", res);

    return 0;
}