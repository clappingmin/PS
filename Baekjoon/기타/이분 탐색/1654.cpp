#include <iostream>
#include <algorithm>

using namespace std;

int K; // 이미 가지고 있는 전선의 수
int N;
long long line[10001];

bool possible(int len)
{
    int cnt = 0;
    for (int i = 0; i < K; i++)
        cnt += (line[i] / len);

    if (cnt >= N)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;

    long long high = 0;

    for (int i = 0; i < K; i++)
    {
        cin >> line[i];
        high = max(high, line[i]);
    }

    long long res = 0;
    long long low = 1;

    while (low <= high)
    {
        long long mid = (high + low) / 2;

        if (possible(mid))
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << '\n';
    
    return 0;
}