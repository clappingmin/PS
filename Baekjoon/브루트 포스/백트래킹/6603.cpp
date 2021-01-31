#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n = -1;
int arr[6];
bool check[50];

void go(int index, int num, vector<int> &input)
{
    if (index == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i < n; i++)
    {
        if (!check[input[i]])
        {
            arr[index] = input[i];
            check[input[i]] = true;
            num = i;
            go(index + 1, num, input);
            check[input[i]] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (n != 0)
    {
        cin >> n;

        if (n == 0)
            break;

        memset(check, false, sizeof(check));

        vector<int> input(n);

        for (int i = 0; i < n; i++)
            cin >> input[i];

        sort(input.begin(), input.end());

        go(0, 0, input);
        cout << '\n';
    }

    return 0;
}