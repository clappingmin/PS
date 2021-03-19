#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 3000000

using namespace std;

int N, D, K, C;
int sushi[MAX], sushi_kind[3001]; //입력 받은 스시정보 저장
int res = 0, cnt = 0;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> D >> K >> C;

    for (int i = 0; i < N; i++)
        cin >> sushi[i];

    //연속해서 먹는 k개를 덱에 넣고 종류를 센다
    for (int i = 0; i < K; i++)
    {
        dq.push_back(sushi[i]);

        sushi_kind[sushi[i]]++;

        if (sushi_kind[sushi[i]] == 1)
            cnt++;

        res = max(res, cnt);
    }

    //슬라이딩 윈도우 기법
    for (int i = 0; i < N - 1; i++)
    {
        //맨 앞 스시를 빼고
        dq.pop_front();
        sushi_kind[sushi[i]]--;

        //해당 스시가 덱에 없을 경우 cnt를 뺀다
        if (sushi_kind[sushi[i]] == 0)
            cnt--;

        //다음 스시를 덱에 넣고
        dq.push_back(sushi[(i + K) % N]);
        sushi_kind[sushi[(i + K) % N]]++;

        //새로운 종류라면 cnt를 증가시킨다.
        if (sushi_kind[sushi[(i + K) % N]] == 1)
            cnt++;

        //만약 덱에 쿠폰 스시가 없을 경우
        if (sushi_kind[C] == 0)
            res = max(res, cnt + 1);

        else
            res = max(res, cnt);
    }
    cout << res << '\n';

    return 0;
}