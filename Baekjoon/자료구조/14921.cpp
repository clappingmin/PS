#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int n;
ll liquid[100000];

int Solution()
{
    int i = 0, j = n - 1;
    ll dif = 200000000;

    while (i < j)
    {
        ll sum = liquid[i] + liquid[j];

        if (abs(sum) < abs(dif))
            dif = sum;

        if (sum<0)
            i++;
        else
        j--;
    }
    return dif;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> liquid[i];

    cout << Solution() << '\n';

    return 0;
}