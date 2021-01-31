#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
int n, s;
int res = 0;

void go(int sum, int index)
{
    if (index == n)
    {
        if (sum == s)
        {
            res += 1;
        }
        return;
    }

    go(sum + num[index], index + 1); //해당 숫자를 선택할 경우
    go(sum, index + 1);              //해당 숫자를 선택하지 않을 경우
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    go(0, 0);

    if (s == 0)
        res -= 1;

    cout << res;

    return 0;
}