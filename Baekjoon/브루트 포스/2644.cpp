#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int n;
int a, b;
vector<int> v[MAX];
int res[MAX];

int bfs()
{
    queue<int> q;
    q.push(a);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == b)
            return res[x];

        for (int i = 0; i < v[x].size(); i++)
        {
            int nx = v[x].at(i);
            if (res[nx] == 0)
            {
                q.push(nx);
                res[nx] = res[x] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;

    cin >> n;      //전체 사람 수
    cin >> a >> b; //촌수를 계산해야 하는 서로 다른 두 사람

    cin >> m; //부모 자식 관계 수

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    cout<<bfs()<<'\n';

    return 0;
}