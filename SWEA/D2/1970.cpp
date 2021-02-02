#include <iostream>
#include <cstring>

using namespace std;
int money[] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
int check[8];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int test = 1; test <= t; test++)
    {
        int input;
        cin >> input;

        memset(check, 0, sizeof(check));
        for (int i = 0; i < 8; i++)
        {
            while (input >= money[i])
            {
                input -= money[i];
                check[i]++;
            }
        }
        cout << '#' << test << '\n';
        for (int i = 0; i < 8; i++)
            cout << check[i] << ' ';
        cout << '\n';
    }

    return 0;
}