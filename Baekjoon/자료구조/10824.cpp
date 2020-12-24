#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, c, d;
    string s1, s2;

    scanf("%d%d%d%d", &a, &b, &c, &d);

    s1 = to_string(a) + to_string(b);
    s2 = to_string(c) + to_string(d);

    long long n1 = stoll(s1);
    long long n2 = stoll(s2);
 
    cout << n1 + n2 << '\n';

    return 0;
}