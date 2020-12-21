#include <iostream>

using namespace std;

int main()
{
    int input, res = 0;

    scanf("%d", &input);

    for (int i = 1; i <= input; i++)
        res += i;

    printf("%d", res);

    return 0;
}