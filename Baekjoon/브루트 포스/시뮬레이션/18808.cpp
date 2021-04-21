#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int A[44][44];
bool visited[44][44];
bool set(int y, int x, vector<vector<int>> &v, int dig)
{
    int a = v.size();
    int b = v[0].size();

    bool check = true;
    for (int i = y; i < y + a; ++i)
    {
        for (int j = x; j < x + b; ++j)
        {
            if (v[i - y][j - x] == 1)
            {
                A[i][j] += dig;
                if (A[i][j] >= 2)
                    check = false;
            }
        }
    }

    return check;
}
void rotate(vector<vector<int>> &v)
{
    int a = v.size();
    int b = v[0].size();

    vector<vector<int>> temp = vector<vector<int>>(b, vector<int>(a));

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
        {
            temp[j][i] = v[a - 1 - i][j];
        }

    v = temp;
}
int main()
{
    cin >> n >> m >> k;

    while (k--)
    {

        int r, c;
        cin >> r >> c;
        vector<vector<int>> v(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
            {
                cin >> v[i][j];
            }

        for (int l = 0; l < 4; ++l)
        {
            bool flg = false;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {

                    if (i + v.size() - 1 < n && j + v[0].size() - 1 < m)
                    {

                        if (set(i, j, v, 1))
                        {
                            flg = true;
                        }
                        if (!flg)
                            set(i, j, v, -1);

                        if (flg)
                            break;
                    }
                }
                if (flg)
                    break;
            }
            if (flg)
                break;

            rotate(v);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (A[i][j] == 1)
                cnt += 1;

    cout << cnt << "\n";
    return 0;
}