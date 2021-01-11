#include <iostream>
#include <vector>

using namespace std;
vector<int> T;

void findT()
{
    int n = 1;

    while (n * (n + 1) / 2 < 1000)
    {
        T.push_back(n * (n + 1) / 2);
        n++;
    }
}
bool checkU(int n)
{

    for (int i = 0; i < T.size(); i++)
    {
        for (int j = 0; j < T.size(); j++)
        {
            for (int k = 0; k < T.size(); k++)
            {
                if (T[i] + T[j] + T[k] == n)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    findT();

    while (t--)
    {
        int n;
        cin >> n;

        if (checkU(n))
            cout << "1" << '\n';
        else
            cout << "0" << '\n';
    }

    return 0;
}