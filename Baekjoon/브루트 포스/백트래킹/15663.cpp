#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
bool check[9];
int n, m;

void go(int index, vector<int> &input)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_num = -1;

    for (int i = 0; i < n; i++)
    {
        if (!check[i] && prev_num != input[i])
        {
            arr[index] = input[i];
            check[i] = true;
            prev_num = input[i];
            go(index + 1, input);
            check[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input.begin(), input.end());

    go(0, input);

    return 0;
}