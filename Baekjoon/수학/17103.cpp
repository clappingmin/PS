#include <iostream>
#include <vector>

using namespace std;

bool check[1000000 + 1]; //소수 아니면 ture
vector<int> oddprime;

void eratosthenes()
{
    check[0] = check[1] = true; //소수 아님

    for (int i = 2; i <= 1000000; i++)
    {
        if (check[i] == false)
        {
            if (i % 2 == 1)
                oddprime.push_back(i);

            for (int j = i + i; j <= 1000000; j += i)
                check[j] = true;
        }
    }
}
int main()
{
    int t;

    scanf("%d", &t);
    eratosthenes();

    while (t--)
    {
        int res = 0, n;
        scanf("%d", &n);

        for (int i = 0; i < oddprime.size(); i++)
        {
            if (n < oddprime[i])
                break;
            for (int j = i; j < oddprime.size(); j++)
            {
                if ((n - oddprime[i]) == oddprime[j])
                {
                    res++;
                    break;
                }
                else if ((n - oddprime[i]) < oddprime[j])
                    break;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}