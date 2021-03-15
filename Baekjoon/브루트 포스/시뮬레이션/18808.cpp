#include <iostream>
#include <vector>

using namespace std;

int n, m, k; //가로, 세로, 스티커 개수
int map[40][40];
int sticker[100][10][10]; //[개수][][]
bool avail;

vector<pair<int, int>> s_info; //스티커 가로, 세로 저장
void check(int s_num)
{
    int sr = s_info[s_num].first;
    int sc = s_info[s_num].second;

    for(int i=0;i<=n-sr;i++)
    {
        for(int j=0;j<=m-sc;j++)
        {
            bool 
        }
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) //스티커 입력
    {
        int r, c;
        cin >> r >> c;

        s_info.push_back({r, c});

        for (int j = 0; j < r; j++)
            for (int t = 0; t < c; t++)
                cin >> sticker[i][j][t];
    }

    for(int i=0;i<k;i++)
    {
        avail = false;
        check(i);
    }

    return 0;
}