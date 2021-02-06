#include <iostream>

using namespace std;

int n, l, r;
int map[50][50];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int res = 0;

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];


    return 0;
}