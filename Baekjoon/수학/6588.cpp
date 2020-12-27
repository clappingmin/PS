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
    int n;
    eratosthenes();

    while (1)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        bool find = false;

        for (int i = 0; i < oddprime.size(); i++)
        {
            for (int j = i; j < oddprime.size(); j++)
            {
                if ((n - oddprime[i]) == oddprime[j])
                {
                    cout << n << " = " << oddprime[i] << " + " << oddprime[j] << "\n";
                    find = true;
                    break;
                }
                else if ((n - oddprime[i]) < oddprime[j])
                    break;
            }
            if (find == true)
                break;
        }
    }
    return 0;
}