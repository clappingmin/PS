#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long sum = 0;
    stack<long long> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long park;
        cin >> park;

        if (s.empty())
            s.push(park);
        else
        {
            while (!s.empty() && s.top() <= park)
            {
                s.pop();
            }
            s.push(park);
        }
        sum += (long long)s.size() - 1;
    }
    cout << sum;

    return 0;
}