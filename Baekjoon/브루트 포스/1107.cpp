#include <iostream>
#include <vector>

using namespace std;

bool broken[10];

int possible(int c)
{
    if (c == 0) //이동할 채널이 0인데
    {
        if (broken[0]) //0버튼이 고장이 났으면
            return 0;  //불가능
        else
            return 1;
    }
    int len = 0;
    while (c > 0)
    {
        if (broken[c % 10])
            return 0;
        len += 1;
        c /= 10;
    }
    return len;
}

int main()
{
    int n, m, now = 100, res;

    scanf("%d%d", &n, &m);

    res = n - 100;

    if (res < 0)
        res = -res;

    for (int i = 0; i < m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        broken[tmp] = true;
    }

    for (int i = 0; i <= 1000000; i++)
    {
        int len = possible(i);

        if (len > 0) //버튼 이동이 가능하면
        {
            int press = i - n;

            if (press < 0)
                press = -press;

            if (res > len + press)
                res = len + press;
        }
    }

    printf("%d", res);

    return 0;
}