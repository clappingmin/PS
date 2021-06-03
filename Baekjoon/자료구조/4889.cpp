#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;

    while (true)
    {
        string str;
        stack<char> s;

        cin >> str;

        if (str[0] == '-')
            break;

        int str_len = str.length();
        int cnt = 0;

        for (int i = 0; i < str_len; i++)
        {

            if (!s.empty() && s.top() == '{' && str[i] == '}')
                s.pop();

            else
                s.push(str[i]);
        }

        while (!s.empty())
        {
            char c1 = s.top();
            s.pop();
            char c2 = s.top();
            s.pop();
            if (c1 == c2)
                cnt++;
            else
                cnt += 2;
        }

        cout << t << ". " << cnt << '\n';
        t++;
    }

    return 0;
}