#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

long long S, T;
bool check;
string op[] = {"*", "+", "-", "/"};
set<long long> se;

long long Calculate(long x, int idx)
{
    if (idx == 0)
        return (x * x);

    else if (idx == 1)
        return (x + x);

    else if (idx == 2)
        return (x - x);

    else if (idx == 3)
        return (x / x);
}

string BFS()
{
    queue<pair<long long, string>> q;
    q.push({S, ""});
    se.insert(S);

    while (!q.empty())
    {
        long long x = q.front().first;
        string s = q.front().second;
        q.pop();

        if (x == T)
        {
            return s;
        }
        for (int i = 0; i < 4; i++)
        {
            long long nx = Calculate(x, i);
            if (nx < 1)
                continue;
            if (se.find(nx) != se.end())
                continue;
            se.insert(nx);
            q.push(make_pair(nx, s + op[i]));
        }
    }
    return "a";
}

void Solution()
{
    string R = BFS();
    if (R!="a")
        cout << R << '\n';
    else
        cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> T;

    if (S == T)
        cout << 0 << '\n';

    else
        Solution();

    return 0;
}