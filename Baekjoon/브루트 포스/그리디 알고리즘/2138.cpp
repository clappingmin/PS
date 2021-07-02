#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int N, answer;
string s, copyS, result;

//스위치 누르는 함수
void push(int idx)
{
    if (idx > 0)
        copyS[idx - 1] = (copyS[idx - 1] == '0') ? '1' : '0';

    copyS[idx] = (copyS[idx] == '0') ? '1' : '0';

    if (idx < N - 1)
        copyS[idx + 1] = (copyS[idx + 1] == '0') ? '1' : '0';
}

void simulation(int idx, int cnt)
{
    if (idx == N - 1)
    {
        //같은지 확인
        bool flag = true;

        for (int i = 0; i < copyS.length(); i++)
            if (copyS[i] != result[i])
            {
                flag = false;
                break;
            }

        if (flag)
            answer = min(answer, cnt);
        //스위치를 눌러보고 다시 확인

        push(idx);

        flag = true;

        for (int i = 0; i < copyS.length(); i++)
            if (copyS[i] != result[i])
            {
                flag = false;
                break;
            }

        if (flag)
            answer = min(answer, cnt + 1);
            
        return;
    }

    //스위치를 안 누른 상태
    if (copyS[idx - 1] == result[idx - 1])
        simulation(idx + 1, cnt);

    //스위치를 누르고
    push(idx);

    if (copyS[idx - 1] == result[idx - 1])
        simulation(idx + 1, cnt + 1);

    //원상복귀
    push(idx);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> s >> result;
    answer = INF;

    //0번째 스위치를 누르지 않은 상태에서 시작
    copyS = s;
    simulation(1, 0);

    //0번째 스위치를 누른 상태에서 시작
    copyS = s;
    push(0);

    simulation(1, 1);

    if (answer == INF)
        cout << -1 << "\n";

    else
        cout << answer << "\n";

    return 0;
}