#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        deque<int> ldq;
        deque<int> rdq;
        string s, res = "";
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<')
            {
                if (ldq.empty())
                    continue;
                else
                {
                    int tmp = ldq.back();
                    ldq.pop_back();
                    rdq.push_back(tmp);
                }
            }
            else if (s[i] == '>')
            {
                if (rdq.empty())
                    continue;
                else
                {
                    int tmp = rdq.back();
                    rdq.pop_back();
                    ldq.push_back(tmp);
                }
            }
            else if (s[i] == '-')
            {
                if (ldq.empty())
                    continue;
                else
                {
                    ldq.pop_back();
                }
            }
            else
                ldq.push_back(s[i]);
        }

        for (int i = 0; i < ldq.size(); i++)
            res += ldq[i];

        for (int i = rdq.size()-1; i >=0; i--)
            res += rdq[i];

        cout << res << '\n';
    }

    return 0;
}