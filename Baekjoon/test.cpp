#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> energy;
int res = INT_MIN;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void dfs(int e, int size)
{
    if (size == 2)
    {
        res = max(res, e);
        return;
    }
    for (int i = 1; i < size - 1; i++)
    {
        int select = energy[i];

        e += energy[i-1] * energy[i+1];
        energy.erase(energy.begin()+i);

        dfs(e,size-1);

        energy.insert(energy.begin()+i, select);
        e -= energy[i-1] * energy[i+1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        energy.push_back(x);
    }

    dfs(0,energy.size());

    cout<<res<<'\n';

    return 0;
}