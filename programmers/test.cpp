#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    int t = 5;
    int check[5][5];

    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (places[t][i][j] == 'P')
                    all_q.push({i, j});
            }
        }

        bool check_final = false;

        while (!all_q.empty())
        {
            bool is_ok = true;
            memset(check, -1, sizeof(check));
            queue<pair<int, int>> q;
            int i = all_q.front().first;
            int j = all_q.front().second;

            all_q.pop();
            q.push({i, j});

            check[i][j] = 0;

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (is_ok == false)
                    break;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                        continue;
                    if (places[t][nx][ny] == 'X' || check[nx][ny] != -1)
                        continue;

                    check[nx][ny] = check[x][y] + 1;
                    q.push({nx, ny});

                    if (places[t][nx][ny] == 'P' && check[nx][ny] <= 2)
                    {
                        is_ok = false;
                        break;
                    }
                }
            }

            if (is_ok == false)
            {
                answer.push_back(0);
                check_final = true;
                break;
            }
        }
        if (check_final == false)
            answer.push_back(1);
    }

    return answer;
}