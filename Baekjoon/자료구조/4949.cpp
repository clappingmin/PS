#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input;

    while (true)
    {
        getline(cin, input);

        stack<char> s;
        bool ok = true;

        if (input == ".")
            break;

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '(' || input[i] == '[')
                s.push(input[i]);

            else if (input[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                    s.push(input[i]);
            }
            else if (input[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                    s.push(input[i]);
            }
        }

        if (s.size() > 0)
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}