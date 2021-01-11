#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n1[26];
int n2[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        bool check = true;

		for (int i = 0; i < 26; i++)
		{
			n1[i] = 0;
			n2[i] = 0;
		}

        for (int i = 0; i < s1.length(); i++)
        {
            n1[s1[i] - 'a']++;
        }

        for (int i = 0; i < s2.length(); i++)
        {
            n2[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (n1[i] != n2[i])
            {
                cout << "Impossible" << '\n';
                check = false;
                break;
            }
        }
        if (check)
            cout << "Possible" << '\n';
    }

    return 0;
}