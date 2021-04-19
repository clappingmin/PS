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

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << ' ';
    }
    return 0;
}