#include <iostream>

using namespace std;

int n, m;
int arr[8];

void go(int index)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {

        arr[index] = i;
        go(index + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    go(0);

    return 0;
}