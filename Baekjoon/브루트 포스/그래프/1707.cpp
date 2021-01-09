#include <iostream>
#include <vector>
#define MAX 20000 + 1

using namespace std;

int n, m;
int color[MAX];
vector<int> g[MAX];

void dfs(int v, int c)
{
    color[v] = c;

    for (int i = 0; i < g[v].size(); i++)
    {
        int next = g[v][i];
        if (color[next] == 0)
            dfs(next, 3 - c);
    }
}
bool isBipartiteG()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            int next = g[i][j];
            if (color[i] == color[next])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) //초기화 작업
        {
            g[i].clear();
            color[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                dfs(i, 1);
            }
        }

        if (isBipartiteG())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}