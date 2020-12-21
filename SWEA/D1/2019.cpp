#include <iostream>

using namespace std;

int main()
{
    int n;
    int res = 1, temp = 0;

    scanf("%d", &n);

    printf("1 ");
    for (int i = 1; i <= n; i++)
    {
        res *= 2;
        printf("%d ", res);
    }

    return 0;
}