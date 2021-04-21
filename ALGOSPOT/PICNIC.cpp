#include <iostream>
#include <cstring>

using namespace std;

int T, N, M; //테스트 케이스 수, 학생 수, 친구 쌍의 수
bool check_friend[10][10];
bool check[10];
int res = 0;

void DFS()
{
    int first = -1;

    for (int i = 0; i < N; i++)
    {
        if (!check[i])
        {
            first = i;
            break;
        }
    }

    if (first == -1) //친구를 다 찾았다
    {
        res += 1;
        return;
    }

    for (int i = first + 1; i < N; i++)
    {
        if (check[i] == 0 && check_friend[i][first])
        {
            check[i] = check[first] = true;
            DFS();
            check[i] = check[first] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        res = 0;
        memset(check_friend, false, sizeof(check_friend));
        memset(check, false, sizeof(check));

        for (int i = 0; i < M; i++)
        {
            int x, y;
            cin >> x >> y;
            check_friend[x][y] = check_friend[y][x] = true;
        }

        DFS();

        cout << res << '\n';
    }

    return 0;
}