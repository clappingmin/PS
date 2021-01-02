#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {

        int n;

        scanf("%d", &n);

        vector<int> v(n + 1);

        v[0] = 1;
        v[1] = 1;
        v[2] = 2;

        for (int i = 3; i <= n; i++)
            v[i] = v[i - 1] + v[i - 2] + v[i - 3];
        
        printf("%d\n",v[n]);
    }
    return 0;
}