#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int res = 0;
    vector<string> v(8);

    for (int i = 0; i < 8; i++)
        cin >> v[i];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                if (v[i][j] == 'F')
                    res++;
            }
            if (i % 2 == 1 && j % 2 == 1)
            {
                if (v[i][j] == 'F')
                    res++;
            }
        }
    }
    cout << res;

    return 0;
}