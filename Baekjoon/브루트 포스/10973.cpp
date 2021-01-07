#include <iostream>
#define MAX 10000 + 1

using namespace std;

int a[MAX];
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int i = n - 1;
    while (i > 0 && a[i] > a[i - 1])
        i -= 1;
    if (i <= 0)
        printf("-1\n");
    //////////////////////////////////////////////////
    else
    {
        int max = 0, tmp;
        for (int j = i; j < n; j++)
        {
            if (a[i - 1] > a[j] && max < a[j])
            {
                max = a[j];
                tmp = j;
            }
        }

        swap(a[i - 1], a[tmp]);

        for (int j = i; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (a[j] < a[k])
                    swap(a[j], a[k]);
        }
        for (int j = 0; j < n; j++)
            printf("%d ", a[j]);
    }

    return 0;
}