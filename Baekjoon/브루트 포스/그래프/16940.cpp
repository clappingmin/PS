#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000 + 1

using namespace std;

int n;
vector<int> graph[MAX];
bool visited[MAX];
vector<int> res;

void bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    res.push_back(1);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++)
        {
            int nx = graph[x][i];

            if (visited[nx])
                continue;

            visited[nx] = true;
            res.push_back(nx);
            q.push(nx);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    bool check = true;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a != res[i])
            check = false;
    }

    if (check)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}