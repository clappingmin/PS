#include <iostream>

using namespace std;

int n, m;
int arr[9];

void go(int index, int num)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {

        arr[index] = i;
        go(index + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    go(0, 1);

    return 0;
}