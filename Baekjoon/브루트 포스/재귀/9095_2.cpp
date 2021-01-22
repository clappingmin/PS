#include <iostream>

using namespace std;
int go(int sum, int count, int goal)
{
    if (sum == goal)
        return 1;
    if (sum > goal)
        return 0;
    int now = 0;
    for (int i = 1; i <= 3; i++)
    {
        now += go(sum + i, count + 1, goal);
    }
    return now;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        int goal;

        cin >> goal;

        cout << go(0, 0, goal) << "\n";
    }

    return 0;
}