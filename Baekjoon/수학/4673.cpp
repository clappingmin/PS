#include <iostream>

using namespace std;

bool gen_num[10001];

int generator(int n)
{
    int sum = n;

    while (true)
    {
        if (n == 0)
            break;
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}
int main()
{
    ios::sync_with_stdio(false);

    for (int i = 1; i <= 10000; i++)
    {
        int n = generator(i);
        if (n <= 10000)
            gen_num[n] = true;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (gen_num[i] == false)
            cout << i << '\n';
    }

    return 0;
}