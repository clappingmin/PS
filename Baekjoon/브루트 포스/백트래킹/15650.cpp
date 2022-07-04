#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool check[9];
void go(int index, int start)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++)
    {
        if (check[i])
            continue;

        arr[index] = i;
        check[i] = true;
        go(index + 1, i + 1);
        check[i] = false;
    }
}

int main()
{
    cin >> n >> m;

    go(0, 1);

    return 0;
}