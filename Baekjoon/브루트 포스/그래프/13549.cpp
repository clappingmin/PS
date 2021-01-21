#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int n, k; //수빈 위치, 동생 위치
bool visited[MAX + 1];
int dist[MAX + 1];

void bfs()
{
    visited[n] = true;
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == k)
        {
            cout << dist[now] << '\n';
            return;
        }

        if (now * 2 <= MAX && !visited[now * 2])
        {
            dist[now * 2] = dist[now];
            visited[now * 2] = true;
            q.push(now * 2);
        }
        if (now - 1 >= 0 && !visited[now - 1])
        {
            dist[now - 1] = dist[now] + 1;
            visited[now - 1] = true;
            q.push(now - 1);
        }
        if (now + 1 <= MAX && !visited[now + 1])
        {
            dist[now + 1] = dist[now] + 1;
            visited[now + 1] = true;
            q.push(now + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    bfs();

    return 0;
}