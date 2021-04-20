#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> H;
    vector<int> bottom(N / 2), top(N / 2);

    for (int i = 0; i < N / 2; i++)
        cin >> bottom[i] >> top[i];

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int res = 987654321; //파괴해야 하는 장애물의 최솟값
    int cnt = 1;

    for (int i = 1; i <= H; i++)
    {
        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());

        temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

        if (res == temp)
            cnt += 1;

        else if (res > temp)
        {
            res = temp;
            cnt = 1;
        }
    }

    cout << res << " " << cnt << '\n';

    return 0;
}