#include <iostream>

using namespace std;

int c[2][7];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; //학생수, 최대 인원 수
    int s, y; //성별, 학년
    int res = 0;

    cin >> n >> k;

    while (n--)
    {
        cin >> s >> y;
        c[s][y]++;
    }

    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (c[j][i] == 0)
                continue;
            else
            {
                if (c[j][i] % k == 0)
                    res += c[j][i] / k;
                else
                    res += c[j][i] / k + 1;
            }
        }
    }

    cout << res << '\n';

    return 0;
}