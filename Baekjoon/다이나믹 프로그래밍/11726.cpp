#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector<int> v(n + 1);

    v[0] = 1;
    v[1] = 1;

    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2] % 10007;

    printf("%d", v[n] % 10007);

    return 0;
}