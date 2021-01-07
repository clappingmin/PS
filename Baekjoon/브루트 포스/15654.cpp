#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;
int output[8];
bool check[10000 + 1];

void go(int index, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", output[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check[input[i]])
            continue;

        output[index] = input[i];
        check[input[i]] = true;
        go(index + 1, n, m);
        check[input[i]] = false;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    input.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    go(0, n, m);

    return 0;
}