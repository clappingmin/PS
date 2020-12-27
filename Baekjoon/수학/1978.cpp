#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, res = 0;
    scanf("%d", &n);

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (int i = 0; i < n; i++)
    {
        bool f = true;
        if (v[i] == 1 || v[i] == 0)
            f = false;
        for (int j = 2; j * j <= v[i]; j++)
        {
            if (v[i] % j == 0)
            {
                f = false;
                break;
            }
        }
        if (f)
            res++;
    }

    printf("%d\n", res);

    return 0;
}