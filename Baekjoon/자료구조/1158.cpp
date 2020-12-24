#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int n, k;
    queue<int> q;
    string str = "<";

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
        q.push(i);

    int cnt = 1;
    while (!q.empty())
    {
        if (cnt < k)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            cnt++;
        }
        else if (cnt == k)
        {
            int tmp = q.front();
            q.pop();
            str += to_string(tmp);
            if (q.size() == 0)
                str += ">";
            else
                str += ", ";

            cnt = 1;
        }
    }
    cout << str;

    return 0;
}