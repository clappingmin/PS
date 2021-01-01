#include <iostream>
using namespace std;

int factorial(int res)
{
    if (res > 2)
        res *= factorial(res - 1);
    return res;
}
int main()
{
    int num, result = 1;

    scanf("%d", &num);

    if (num != 0)
        result = factorial(num);

    cout << result;

    return 0;
}