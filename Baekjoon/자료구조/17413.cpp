#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    bool tag = false;
    stack<char> s;

    getline(cin, str);
    str += '\n';

    for (char ch : str)
    {

        if (tag == true)
        {
            if (ch == '>')
                tag = false;

            printf("%c", ch);
        }

        else if (tag == false)
        {
            if (ch == ' ' || ch == '\n' || ch == '<')
            {
                if (ch == '<')
                    tag = true;
                while (!s.empty())
                {
                    printf("%c", s.top());
                    s.pop();
                }
                printf("%c", ch);
            }
            else
                s.push(ch);
        }
    }
    return 0;
}