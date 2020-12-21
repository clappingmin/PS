#include <iostream>
using namespace std;

int N;
int a[1000000];
int mx;
long long sum;

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        
        sum = 0;
        mx = a[N - 1];
        
        for (int i = N - 2; i >= 0; i--)
        {
            if (a[i] > mx)
                mx = a[i];
            else
                sum += mx - a[i];
        }

        printf("#%d %lld\n", tc, sum);
    }

    return 0;
}