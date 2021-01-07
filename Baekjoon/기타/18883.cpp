#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;
    int num = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << j + (i * m) + 1;

            if (j == m - 1)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}