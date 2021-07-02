#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

bool frimenum[10000];
bool visited[10000];

void find_frime()
{
    memset(frimenum, true, sizeof(frimenum));

    for (int i = 2; i < 10000; i++)
    {
        for (int j = 2; i * j < 10000; j++)
        {
            frimenum[i * j] = false;
        }
    }
}

void make_num2(int num1, int num2)
{
    queue<pair<int, int>> q;
    q.push({num1, 0});
    visited[num1] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x == num2)
        {
            cout << cnt << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                string s = to_string(x);
                s[i] = j + '0';

                int nx = stoi(s);

                if (nx < 1000 || nx > 9999)
                    continue;

                if (frimenum[nx] == false)
                    continue;

                if (visited[nx] == true)
                    continue;

                visited[nx] = true;
                q.push({nx, cnt + 1});
            }
        }
    }
    cout << "impossible\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    find_frime();

    while (t--)
    {
        int num1, num2;

        cin >> num1 >> num2;

        memset(visited, false, sizeof(visited));

        make_num2(num1, num2);
    }

    return 0;
}