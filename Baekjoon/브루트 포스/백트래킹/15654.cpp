#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
bool check[10000 + 1];

void go(int index, vector<int> &input)
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

    for (int i = 0; i < n; i++)
    {
        if (check[input[i]])
            continue;

        arr[index] = input[i];
        check[input[i]] = true;
        go(index + 1, input);
        check[input[i]] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> input;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }
    sort(input.begin(), input.end());

    go(0, input);

    return 0;
}