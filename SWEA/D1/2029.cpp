#include <iostream>

using namespace std;

int main()
{
    int t, a, b;

    scanf("%d",&t);

    for (int i = 1; i <= t; i++)
    {   
        scanf("%d%d",&a,&b);
        printf("#%d %d %d\n", i, a / b, a % b);
    }
    return 0;
}