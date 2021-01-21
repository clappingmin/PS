#include <iostream>
#include <queue>
#include <stack>
#define MAX 100000

using namespace std;

int n, k; //수빈 위치, 동생 위치
int dist[MAX + 1];
int visited[MAX + 1];

void bfs(int i)
{
    visited[i] = -1; //시작
    dist[i] = 0;
    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == k)
        {
            stack<int> res;
            cout << dist[x] << "\n";

            while (x != -1)
            {
                res.push(x);
                x = visited[x];
            }
            while(!res.empty())
            {
                cout<<res.top()<<' ';
                res.pop();
            }
 
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            int nx;
            if (i == 0)
                nx = x + 1;
            else if (i == 1)
                nx = x - 1;
            else
                nx = 2 * x;

            if (nx < 0 || nx > MAX || dist[nx] || visited[nx] == -1)
                continue;

            dist[nx] = dist[x] + 1;
            visited[nx] = x;
            q.push(nx);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    bfs(n);

    return 0;
}