#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    int n;
    stack<char> left, right;

    cin >> str;
    scanf("%d", &n);

    for (char ch : str)
        left.push(ch);

    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "P") //왼쪽에 추가
        {
            char tmp;
            cin >> tmp;
            left.push(tmp);
        }
        else if (cmd == "B")    //삭제
        {
            if (!left.empty())
                left.pop();
        }

        else if (cmd == "L")
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == "D")
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
    }

    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty())
    {
        printf("%c", right.top());
        right.pop();
    }
    return 0;
}