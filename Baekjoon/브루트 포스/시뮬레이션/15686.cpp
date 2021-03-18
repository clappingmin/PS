#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int map[50][50];
int res = 987654321;

vector<pair<int, int>> chicken, house, v;
bool check[13];

int Solution()
{
    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int x1 = house[i].first;
        int y1 = house[i].second;
        int d = 987654321;

        for (int j = 0; j < v.size(); j++)
        {
            int x2 = v[j].first;
            int y2 = v[j].second;
            int dist = abs(x2 - x1) + abs(y2 - y1);

            d = min(d, dist);
        }
        sum += d;
    }
    return sum;
}

void Select(int index, int cnt)
{
    if (cnt == M)
    {
        res = min(res, Solution());
        return;
    }
    for (int i = index; i < chicken.size(); i++)
    {
        if (check[i] == true)
            continue;

        check[i] = true;
        v.push_back(chicken[i]);

        Select(i, cnt + 1);

        check[i] = false;
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
                house.push_back({i, j});
            else if (map[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    Select(0, 0);
    Solution();

    cout << res << '\n';

    return 0;
}