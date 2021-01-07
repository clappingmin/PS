#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal(vector<int> &a)
{
    int sum = 0;
    for (int i = 1; i < a.size(); i++)
        sum += abs(a[i - 1] - a[i]);

    return sum;
}
int main()
{
    int n, res = 0;

    scanf("%d", &n);

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a.begin(), a.end());

    do
    {
        res = max(res,  cal(a));
    } while (next_permutation(a.begin(), a.end()));

    printf("%d", res);

    return 0;
}