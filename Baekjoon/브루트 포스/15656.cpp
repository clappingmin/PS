#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;
vector<int> output;

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
        output[index] = input[i];
        go(index + 1, n, m);

    }
}
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    input.resize(n);
    output.resize(m);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    sort(input.begin(), input.end());

    go(0, n, m);


    return 0;
}