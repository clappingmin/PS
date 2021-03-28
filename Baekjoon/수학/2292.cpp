#include <iostream>

using namespace std;

int N, res = 0;

int Solution()
{
    int res = 1;
    int cnt = 1;

    while (cnt < N)
    {
        cnt += res * 6;
        res += 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    cout << Solution();

    return 0;
}