#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 25

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int apt[MAX][MAX];
int n;
vector<int> res;
queue<pair<int, int>> q;

int bfs(int i, int j)
{
    q.push(make_pair(i, j));
    apt[i][j] = 0;
    int cnt = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int direction = 0; direction < 4; direction++)
        {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if(!apt[nx][ny])
            continue;

            apt[nx][ny] = 0;
            cnt++;
            q.push(make_pair(nx, ny));
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            apt[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (apt[i][j])
                res.push_back(bfs(i, j));
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';

    return 0;
}