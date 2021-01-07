#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, res = 0;
    while (~scanf("%d", &n))
    {
        res += n;
    }
    cout << res;

    return 0;
}
