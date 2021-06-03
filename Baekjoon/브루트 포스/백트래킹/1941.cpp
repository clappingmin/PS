#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

char map[5][5];
int res = 0;
bool check_student[25];
bool check_map[5][5];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool count_s()
{
    int s_cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (check_student[i])
        {
            if (map[i / 5][i % 5] == 'S')
                s_cnt++;
        }
    }
    if (s_cnt >= 4)
    {
        return true;
    }

    return false;
}
bool connected_student() 
{
    memset(check_map, false, sizeof(check_map));
    int student_cnt = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < 25; i++)
    {
        if (check_student[i])   //선택된 사람 중 한명을 시작점으로
        {
            q.push({i / 5, i % 5});
            check_map[i / 5][i % 5] = true;
            student_cnt++;
            break;
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;

            if (check_map[nx][ny])
                continue;

            int temp = nx * 5 + ny;

            check_map[nx][ny] = true;

            if (check_student[temp])   
            {
                student_cnt++;
                q.push({nx, ny});
            }
        }
    }
    if (student_cnt == 7)
        return true;

    return false;
}

bool is_ok()
{
    if (!count_s())  //2.이다솜파가 4명 이상인지 확인
        return false;
    if (!connected_student())   //학생들이 서로 연결되어 있는지 확인
        return false;

    return true;
}

void select_student(int idx, int cnt)
{
    if (cnt == 7)
    {
        if (is_ok())
            res += 1;
        return;
    }

    for (int i = idx; i < 25; i++)
    {
        if (check_student[i])
            continue;

        check_student[i] = true;
        select_student(i, cnt + 1);
        check_student[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 5; j++)
            map[i][j] = s[j];
    }

    select_student(0, 0); //1.7명의 학생 선택하기
    cout << res << '\n';
    return 0;
}