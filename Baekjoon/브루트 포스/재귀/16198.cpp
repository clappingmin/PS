#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int bead[10];
int max_energy = INT_MIN;

void select_bead(vector<int> &v, int energy)
{
    if (v.size() == 2)
    {
        max_energy = max(max_energy, energy);
        return;
    }

    for (int i = 1; i < v.size() - 1; i++)
    {
        int select = v[i];

        v.erase(v.begin() + i);
        select_bead(v, energy + (v[i - 1] * v[i]));
        v.insert(v.begin() + i, select);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    select_bead(v, 0);

    cout << max_energy;

    return 0;
}