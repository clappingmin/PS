#include <iostream>

using namespace std;

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {
        int m, n, x, y;
        bool find = false;

        scanf("%d%d%d%d", &m, &n, &x, &y);

        x -= 1; //나머지연산을 쉽게 하기 위해서
        y -= 1;

        for (int i = x; i < n * m; i += m)  //년은 x로 고정
        {
            if (i % n == y)
            {
                printf("%d\n", i + 1);
                find = true;
                break;
            }
        }
        if (find == false)
            printf("-1\n");
    }

    return 0;
}