#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    stack<int> s;

    while (n--)
    {
        string cmd;
        int n;
        cin >> cmd;

        if (cmd == "push")
        {
            scanf("%d", &n);
            s.push(n);
        }
        else if (cmd == "pop")
        {
            if (s.empty())
                printf("-1\n");
            else
            {
                int tmp = s.top();
                s.pop();
                printf("%d\n", tmp);
            }
        }
        else if (cmd == "size")
        {
            printf("%d\n", s.size());
        }
        else if (cmd == "empty")
        {
            if (s.empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if (cmd == "top")
        {
            if (s.empty())
                printf("-1\n");
            else
                printf("%d\n", s.top());
        }
    }
    return 0;
}