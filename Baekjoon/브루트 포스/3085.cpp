#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int count(vector<string> &c)
{
    int res = 0;
    for (int i = 0; i < c.size(); i++)
    {
        int cnt = 1;
        for (int j = 1; j < c.size(); j++) //행비교
        {
            if (c[i][j] == c[i][j - 1])
                cnt++;
            else
                cnt = 1;

            if (cnt > res)
                res = cnt;
        }
        cnt = 1;
        for (int j = 1; j < c.size(); j++) //열비교
        {
            if (c[j][i] == c[j - 1][i])
                cnt++;
            else
                cnt = 1;

            if (cnt > res)
                res = cnt;
        }
    }
    return res;
}

int main()
{
    int n, res = 0;
    scanf("%d", &n);

    vector<string> candy(n);

    for (int i = 0; i < n; i++)
        cin >> candy[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++) //왼쪽 사탕 바꾸기
        {
            swap(candy[i][j], candy[i][j - 1]);
            int temp = count(candy);

            if (res < temp)
                res = temp;

            swap(candy[i][j], candy[i][j - 1]);

            swap(candy[j][i], candy[j - 1][i]); //위쪽 사탕 바꾸기
            temp = count(candy);

            if (res < temp)
                res = temp;
            swap(candy[j][i], candy[j - 1][i]);
        }
    }

    printf("%d", res);

    return 0;
}