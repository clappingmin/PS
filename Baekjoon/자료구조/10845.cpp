#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{

    int n;
    queue<int> q;
    scanf("%d", &n);

    while (n--)
    {
        string cmd;

        cin >> cmd;

        if (cmd == "push")
        {
            int p;
            scanf("%d", &p);
            q.push(p);
        }
        else if (cmd == "pop")
        {
            if (q.empty())
                printf("-1\n");
            else
            {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            printf("%d\n", q.size());
        }
        else if (cmd == "empty")
        {
            if (q.empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if (cmd == "front")
        {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else if (cmd == "back")
        {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }

    return 0;
}