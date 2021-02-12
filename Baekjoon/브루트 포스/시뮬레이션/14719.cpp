#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, sum = 0;
    int left, right;

    cin >> h >> w;

    vector<int> v(w);

    for (int i = 0; i < w; i++)
        cin >> v[i];

    for (int i = 1; i < w; i++)
    {
        left = right = v[i];
        for (int j = 0; j < i; j++)
            left = max(left, v[j]); //왼쪽 검사

        for (int j = i + 1; j < w; j++)
            right = max(right, v[j]); //오른쪽 검사

        int temp = min(left, right);
        
        sum += temp - v[i];
    }

    cout << sum << '\n';

    return 0;
}