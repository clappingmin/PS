#include <iostream>

using namespace std;

int a[8];
void go(int index, int start, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++)
    {
        a[index] = i;
        go(index + 1, i, n, m);
    }
}
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    go(0, 1, n, m);

    return 0;
}