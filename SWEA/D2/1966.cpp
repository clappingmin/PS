#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        vector<int> v(n);

        for (int j = 0; j < n; j++)
            scanf("%d", &v[j]);

        sort(v.begin(), v.end());

        printf("#%d ", i);
        for (int j = 0; j < n; j++)
            printf("%d ", v[j]);
        
        printf("\n");
    }
    return 0;
}