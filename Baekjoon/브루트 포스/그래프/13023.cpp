#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[2001];
vector<int> graph[2001];

int friends = 0;

void dfs(int start)
{
    visited[start] = true;
    friends++;

    if (friends == 5)
    {
        cout << 1;
        exit(0); // 프로그램 종료
    }

    for (int i = 0; i < graph[start].size(); i++)
    {
        int node = graph[start][i];
        if (!visited[node])
            dfs(node);
    }
    visited[start] = false;
    friends--;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 0; i < n; i++)
        dfs(i);

    cout << 0;

    return 0;
}