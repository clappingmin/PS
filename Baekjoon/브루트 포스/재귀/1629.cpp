#include <iostream>
#define ll long long

using namespace std;

ll pow(ll a, ll b, ll c)
{
    if (b == 1)
        return a % c;

    ll val = pow(a, b / 2, c);
    val = val * val % c;

    if (b % 2 == 0)
        return val;
        
    return val * a % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //a를 b번 곱한수를 c로 나눈 나머지를 출력
    int a, b, c;

    cin >> a >> b >> c;

    cout << pow(a, b, c) << '\n';

    return 0;
}