#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>    //round

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        vector<int> v(10);
        double res = 0;

        for (int j = 0; j < 10; j++)
            scanf("%d", &v[j]);

        sort(v.begin(), v.end());

        for (int j = 1; j < 9; j++)
            res += v[j];
        
        res = round(res/8);

        printf("#%d %.0lf\n", i, res);
    }
    return 0;
}