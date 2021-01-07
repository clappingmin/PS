#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s, res = 0;

    scanf("%d%d", &n, &s);

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for (int i = 1; i < (1 << n); i++)  // 000000 ~ 111111
    {
        //k는 0부터 시작하여 n - 1까지 가면서 해당 부분집합(i의 값 자체가 부분집합임)이 어떤 index의 원소를 가지고 있는 확인한다.
        int sum = 0;
        for (int k = 0; k < n; k++)
        {
            //해당 부분집합에 들어있는 값을 더해준다.
            if (i & (1 << k))
            {
                sum += v[k];
            }
        }
        if (sum == s)
            res++;
    }

    printf("%d\n", res);

    return 0;
}