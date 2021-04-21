#include <iostream>
#include <string>

using namespace std;

string s, t, res_s, res_t;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;

    int tmp = LCM(s.size(), t.size());

    for (int i = 0; i < tmp / s.size(); i++)
        res_s += s;

    for (int i = 0; i < tmp / t.size(); i++)
        res_t += t;

    if (res_s.compare(res_t))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}