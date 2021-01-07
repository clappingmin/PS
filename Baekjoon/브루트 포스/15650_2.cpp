#include <iostream>

using namespace std;

int a[10];
void go(int index, int selected, int n, int m)
{
    if (selected == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);

        printf("\n");
        return;
    }
    if (index > n)
        return;
    a[selected] = index;
    go(index + 1, selected + 1, n, m);
    a[selected] = 0;
    go(index+1,selected,n,m);
}
int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    go(1, 0, n, m);

    return 0;
}