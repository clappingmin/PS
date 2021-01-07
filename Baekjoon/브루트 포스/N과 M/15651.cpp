#include <iostream>
#define MAX 7

using namespace std;

int a[MAX];

void go(int index, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        a[index] = i;
        go(index + 1, n, m);
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    go(0, n, m);
    return 0;
}