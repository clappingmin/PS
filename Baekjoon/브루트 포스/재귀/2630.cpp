#include <iostream>

using namespace std;
int n, w = 0, b = 0;
int map[129][129];

void go(int x, int y, int n)
{
    int temp = 0;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (map[i][j]) //파란색일 경우
                temp++;
        }
    }
    if (!temp) //다 하얀색일 경우
        w++;
    else if (temp == n * n) //다 파란색일 경우
        b++;
    else //하얀색과 파란색이 섞여있을 경우
    {
        go(x, y, n / 2);
        go(x, y + n / 2, n / 2);
        go(x + n / 2, y, n / 2);
        go(x + n / 2, y + n / 2, n / 2);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    go(0, 0, n);

    cout<<w<<'\n'<<b;

    return 0;
}