#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<int> s;
    int n;
    bool found = true;
    string ans = "";

    scanf("%d", &n);

    int m = 0; //현재까지 본 숫자

    while (n--)
    {
        int x;

        scanf("%d", &x);

        if (m < x)
        {
            while (m < x)
            {
                s.push(++m);
                ans += '+';
            }
            s.pop();
            ans += '-';
        }
        else
        {
            if (s.top() == x)
            {
                s.pop();
                ans += '-';
            }
            else
            {
                found = false;
                break;
            }
        }
    }
    if (found == false)
        printf("NO\n");
    else
    {
        for (char ch : ans)
        {
            printf("%c\n", ch);
        }
    }

    return 0;
}
