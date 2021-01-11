#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string map[50];
string white[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}};

string black[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}};

int whiteFirst(int x, int y)
{
    int cnt = 0;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (map[i][j] != white[i - x][j - y])
                cnt++;
        }
    }

    return cnt;
}
int blackFirst(int x, int y)
{
    int cnt = 0;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if (map[i][j] != black[i - x][j - y])
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, res = 2500;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> map[i];

    for (int i = 0; i + 7 < n; i++)
        for (int j = 0; j + 7 < m; j++)
            res = min(res, min(whiteFirst(i, j), blackFirst(i, j)));

    cout << res << '\n';

    return 0;
}