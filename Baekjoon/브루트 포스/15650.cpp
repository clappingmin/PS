#include <iostream>
#define MAX 8
using namespace std;

int a[MAX];
void go(int index, int start, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", a[i]);

        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++)
    {
        a[index] = i;
        go(index + 1, i + 1, n, m);
    }
}

int main()
{ //1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
    int n, m;

    scanf("%d%d", &n, &m);

    go(0, 1, n, m);

    return 0;
}