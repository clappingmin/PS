#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<long long> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int high = N - 1;
    int low = 0;

    int res_h = N - 1, res_l = 0;

    long long z = 10000000000000;

    while (low < high)
    {
        long long temp = v[high] + v[low];

        if (temp == 0)
        {
            res_h = high;
            res_l = low;
            break;
        }

        else if (z > abs(temp))
        {
            res_h = high;
            res_l = low;
            z = abs(temp);
        }
        if (temp < 0)
            low += 1;

        else if (temp > 0)
            high -= 1;
    }

    cout << v[res_l] << " " << v[res_h] << '\n';

    return 0;
}