#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int a, b, c;
bool check[3][501];

int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    check[0][a] = true;
    check[1][b] = true;
    check[2][c] = true;

    q.push({{a, b}, c});

    while (!q.empty())
    {
        int num[3];
        num[0] = q.front().first.first;
        num[1] = q.front().first.second;
        num[2] = q.front().second;

        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<"\n";
        q.pop();

        if (num[0] == num[1] && num[1] == num[2])
            return 1;

        int min_num = INT_MAX, min_i;
        int max_num = INT_MIN, max_i;
        int temp_i;

        for (int i = 0; i < 3; i++)
        {
            if (max_num < num[i])
            {
                max_num = num[i];
                max_i = i;
            }
            if (min_num > num[i])
            {
                min_num = num[i];
                min_i = i;
            }
        }

        for(int i =0;i<3;i++)
        {
            if(i!=max_i&&i!=min_i)
            {
                temp_i = i;
                break;
            }
        }

        cout<<max_i<<" "<<min_i<<" "<<temp_i<<"\n";

        max_num -= min_num;
        min_num += min_num;

        if (max_num > 500 || min_num < 1)
            continue;

        if (check[max_i][max_num] || check[min_i][min_num])
            continue;

        check[max_i][max_num] = true;
        check[min_i][min_num] = true;

        q.push({{max_num, min_num}, num[temp_i]});
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << bfs();

    return 0;
}