#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int a[MAX + 1];
int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int i = n - 1;
    int tmp2, tmp = 10000; //i-1보다 큰 수 중 제일 작은 수

    while (i > 0 && a[i] < a[i - 1])
        i -= 1;
    if (i <= 0)
        printf("-1\n");
    else
    {
        for (int j = i; j < n; j++)
        {
            if (a[i - 1] < a[j] && a[j] < tmp)
            {
                tmp = a[j];
                tmp2 = j;
            }
        }
        swap(a[i - 1], a[tmp2]);

        for (int j = i; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (a[k] < a[j])
                    swap(a[j], a[k]);
        }

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
    }

    return 0;
}