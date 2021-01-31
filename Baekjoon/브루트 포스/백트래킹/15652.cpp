#include <iostream>

using namespace std;

int arr[8];
bool check[8];
int n, m; //1부터 N까지 수를 가지는 m길이의 배열

void go(int index, int num)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = num; i <= n; i++)
    {
        arr[index] = i;
        num = i;
        go(index + 1, num);
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