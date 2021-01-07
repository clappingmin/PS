#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, res = 0;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> x;

    sort(v.begin(), v.end());

    int i = 0, j = n - 1;

    while (i != j && i < n && j >= 0)
    {
        if (i >= j)
            break;
        if (v[i] + v[j] == x)
        {
            res += 1;
            i++;
            j--;
        }
        else if (v[i] + v[j] < x)
            i++;
        else if (v[i] + v[j] > x)
            j--;
    }

    cout << res;

    return 0;
}