#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int n;
    string cmd;
    scanf("%d", &n);
    deque<int> dq;

    while (n--)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            int p;
            scanf("%d", &p);
            dq.push_front(p);
        }
        else if (cmd == "push_back")
        {
            int p;
            scanf("%d", &p);
            dq.push_back(p);
        }
        else if (cmd == "pop_front")
        {
            if (dq.empty())
                printf("-1\n");
            else
            {
                int p;
                p = dq.front();
                printf("%d\n", p);
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (dq.empty())
                printf("-1\n");
            else
            {
                int p;
                p = dq.back();
                printf("%d\n", p);
                dq.pop_back();
            }
        }
        else if (cmd == "size")
            printf("%d\n", dq.size());

        else if (cmd == "empty")
        {
            if (dq.empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if (cmd == "front")
        {
            if (dq.empty())
                printf("-1\n");
            else
                printf("%d\n", dq.front());
        }
        else if (cmd == "back")
        {
            if (dq.empty())
                printf("-1\n");
            else
                printf("%d\n", dq.back());
        }
    }
    return 0;
}