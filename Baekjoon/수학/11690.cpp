#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long mod = (long long)1 << 32;
bool is_prime[100000001];
vector<int> plist;

void sieve(int n)
{
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= n; j += i)
        {
            is_prime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    sieve(n);

    long long res = 1;

    plist.push_back(2);

    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
            plist.push_back(i);
    }
    
    for (auto &prime : plist)
    {
        long long power = prime;
        while (power * prime <= n)
        {
            power *= prime;
        }
        res = (res * power) % mod;
    }

    cout << res;

    return 0;
}
