#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M;
vector<long long> v;

bool possible(long long len)
{
    long long temp = 0;

    for (int i = 0; i < N; i++)
    {
        if (len < v[i])
            temp += (v[i] - len);
    }
    if (temp >= M)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    long long high = 0, low = 1;

    for (int i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
        high = max(high, v[i]);
    }

    long long res = 0;

    while (low <= high)
    {
        long long mid = (high + low) / 2;

        if (possible(mid))
        {
            if (res < mid)
                res = mid;
            low = mid + 1;
        }
        else

            high = mid - 1;
    }

    cout << res << '\n';
    return 0;
}