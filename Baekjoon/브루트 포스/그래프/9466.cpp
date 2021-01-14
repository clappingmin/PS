#include <iostream>
#include <cstring>
#define MAX 100000 + 1

using namespace std;

int n, cnt;
int want[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int start)
{
    visited[start] = true;

    int next = want[start];

    if (!visited[next])
        dfs(next);

    else if (!done[next])
    {
        for (int i = next; i != start; i = want[i])
            cnt++;
        cnt++; //자기 자신도 포함
    }
    done[start] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));

        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> want[i];

        cnt = 0;

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                dfs(i);

        cout << n - cnt << '\n';
    }

    return 0;
}