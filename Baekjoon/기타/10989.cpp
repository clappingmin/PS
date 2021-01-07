#include <iostream>

using namespace std;

int arr[10000 + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << "\n";

    return 0;
}