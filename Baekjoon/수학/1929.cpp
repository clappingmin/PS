#include <iostream>

using namespace std;

// int prime[10000];    //소수 저장
int pn = 0;              //소수 개수
bool check[1000000 + 1]; // 지워졌으면 true

void eratosthenes(int m, int n)
{
    check[0] = check[1] = true; //0과 1은 소수가 아님

    for (int i = 2; i <= n; i++)
    {
        if (check[i] == false) //지워지지 않았으면
        {
            // prime[pn++] = i;
            if (i >= m)
                printf("%d\n", i);

            for (int j = i + i; j <= n; j += i)
                check[j] = true; //소수 아님
        }
    }
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n); //m이상 n이하

    eratosthenes(m, n);

    // for (int i = 0; i < pn; i++)
    // {
    //     if (prime[i] >= m)
    //         printf("%d\n", prime[i]);
    // }

    return 0;
}