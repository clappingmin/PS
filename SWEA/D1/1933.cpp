#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;
        cout << i << " ";
    }

    return 0;
}