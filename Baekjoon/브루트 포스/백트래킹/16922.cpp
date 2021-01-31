#include <iostream>

using namespace std;

int n, res = 0;
int rome[4] = {1, 5, 10, 50};
int check[1000];

void go(int index, int num, int sum)
{
    if (index == n)
    {
        check[sum] += 1;

        if (check[sum] == 1){
            res++;
        }

        return;
    }

    for (int i = num; i < 4; i++)
    {
        sum += rome[i];
        num = i;
        go(index + 1, num, sum);
        sum -= rome[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    go(0, 0, 0);

    cout << res << '\n';

    return 0;
}