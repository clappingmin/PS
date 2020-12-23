#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);
    cin.ignore();

    while (t--)
    {
        stack<char> s;
        string str;
        int size = 0;
        cin >> str;

        for (char ch : str)
        {
            if (ch == '(')
            {
                s.push(ch);
                size++;
            }
            else if (ch == ')')
            {
                if (s.empty())
                {
                    size--;
                    break;
                }
                else
                {
                    s.pop();
                    size--;
                }
            }
        }
        if (size < 0 || !s.empty())
            printf("NO\n");
        else if (size == 0)
            printf("YES\n");
    }
    return 0;
}