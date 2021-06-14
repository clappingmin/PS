#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<char> sign;

bool check(vector<int> &v)
{
    for (int i = 0; i < n; i++)
    {
        if (sign[i] == '<' && v[i] > v[i + 1])
            return false;

        else if (sign[i] == '>' && v[i] < v[i + 1])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        sign.push_back(c);
    }

    vector<int> small, big;

    for (int i = 0; i <= n; i++)
    {
        small.push_back(i);
        big.push_back(9 - i);
    }

    do
    {
        if (check(small))
            break;

    } while (next_permutation(small.begin(), small.end()));

    do
    {
        if (check(big))
            break;

    } while (prev_permutation(big.begin(), big.end()));

    for (int i = 0; i < n+1; i++)
        cout << big[i];
    cout << '\n';

    for (int i = 0; i < n + 1; i++)
        cout << small[i];
    cout << '\n';
    
    return 0;
}