#include <iostream>

using namespace std;

int main()
{
    //가위는 1, 바위는 2, 보는 3
    int a, b;
    scanf("%d%d", &a, &b);

    if (a == 1 && b == 3)
        printf("A");
    else if (a > b)
        printf("A");
    else
        printf("B");

    return 0;
}
