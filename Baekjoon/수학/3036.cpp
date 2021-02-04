#include <iostream>

using namespace std;

int input[100];

void gcd(int a, int b, int index)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    cout << input[0] / a << "/" << input[index] / a << '\n';
}
int main()
{
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> input[i];

    for (int i = 1; i < n; i++)
        gcd(input[0], input[i], i);

    return 0;
}