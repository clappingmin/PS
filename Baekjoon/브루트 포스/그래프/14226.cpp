#include <iostream>
#include <queue>
#include <cstring>

#define MAX 1000

using namespace std;

int s;
int dist[MAX + 1][MAX + 1]; //화면, 클립보드

void bfs()
{
    dist[1][0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));

    while (!q.empty())
    {
        int screen = q.front().first;
        int clip = q.front().second;
        q.pop();

        if (screen == s)
        {
            cout << dist[screen][clip] << '\n';
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            int ns = screen;
            int nc = clip;

            if (i == 0) //복사해서 클립보드에 저장
            {
                ns = screen;
                nc = screen;
            }
            else if (i == 1) //클립보드 이모티콘 복붙
            {
                if (clip != 0) //클립보드가 비어있지 않을 경우
                {
                    ns = screen + clip;
                    nc = clip;
                }
            }
            else if (i == 2)    //화면에서 이모티콘 1개 삭제
            {
                ns = screen - 1;
                nc = clip;
            }
            if (ns < 0 || ns > MAX || nc < 0 || nc > MAX)
                continue;
            if (dist[ns][nc] > -1)
                continue;
            dist[ns][nc] = dist[screen][clip] + 1;
            q.push(make_pair(ns, nc));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    memset(dist, -1, sizeof(dist));

    bfs();

    return 0;
}