#include <iostream>
#include <vector>
#include <algorithm> //min()

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector<int> v(n + 1);

    v[0] = 0;
    v[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        v[i] = v[i - 1] + 1;

        if (i % 2 == 0)
            v[i] = min(v[i], v[i / 2] + 1);

        if (i % 3 == 0)
            v[i] = min(v[i], v[i / 3] + 1);
    }
    printf("%d", v[n]);

    return 0;
}