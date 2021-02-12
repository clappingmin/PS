#include <iostream>

using namespace std;

int n, k, res = 1;
int dist[100001];
bool check[100001];

void go(int now, int cnt)
{
    if (now == k)
    {
        dist[cnt] += 1;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        int tmp = now;
        bool flag = false;
        if (i == 0)
        {
            cout << now << " 0" << '\n';
            if (2 * now <= 100000 && check[2 * now] == false)
            {
                tmp = 2 * now;
                flag = true;
            }
        }

        else if (i == 1)
        {
            cout << now << " 1" << '\n';
            if (now + 1 <= 100000 && check[now + 1] == false)
            {
                tmp = now + 1;
                flag = true;
            }
        }

        else if (i == 2)
        {
                        cout << now << " 2" << '\n';
            if (now - 1 >= 0 && check[now - 1] == false)
            {
                tmp = now - 1;
                flag = true;
            }
        }
        if (flag == true)
        {
            check[tmp] = true;
            go(tmp, cnt + 1);
            check[tmp] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    if (n != k)
    {
        check[n] = true;
        go(n, 0);

        for (int i = 0; i <= 100000; i++)
        {
            if (dist[i] != 0)
            {
                cout << i << '\n';
                cout << dist[i] << '\n';
                break;
            }
        }
    }
    else if (n == k)
    {
        cout << 0 << '\n';
        cout << 0 << '\n';
    }

    return 0;
}