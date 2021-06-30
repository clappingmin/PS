#include <iostream>
#include <queue>

using namespace std;

int map[101];
int check[101];
int n, k; //사다리 개수, 뱀 개수

void bfs()
{
    queue<int> q;
    check[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int dice = 1; dice <= 6; dice++)
        {
            int nx = x + dice;

            if (nx > 100)
                continue;

            if (map[nx] != 0)
                nx = map[nx];

            if (check[nx])
                continue;

            check[nx] = check[x] + 1;
            q.push(nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n + k; i++)
    {
        int u, v;

        cin >> u >> v;

        map[u] = v;
    }

    bfs();
    cout << check[100];

    return 0;
}