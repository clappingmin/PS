#include <iostream>
#include <cstring>
#define MAX 1000 + 1

using namespace std;

int n, cnt = 0;
int arr[MAX];
bool visited[MAX], done[MAX];

void dfs(int idx)
{
    visited[idx] = true;

    int next = arr[idx];

    if (!visited[next])
        dfs(next);

    else if (!done[next])
        cnt++;
        
    done[idx] = true;
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
            cin >> arr[i];

        cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        cout << cnt << '\n';
    }

    return 0;
}