#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool res_check[2000000];
int N;
vector<int> arr, input;
bool check[20];

void go(int index, int cnt, int num)
{
    if (cnt == num)
    {
        int temp = 0;
        for (int i = 0; i < num; i++)
            temp += input[arr[i]];

        if (res_check[temp] == false)
            res_check[temp] = true;

        return;
    }

    for (int i = index; i < N; i++)
    {
        if (check[i])
            continue;

        check[i] = true;
        arr.push_back(i);
        go(i, cnt + 1, num);
        arr.pop_back();
        check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        input.push_back(x);
    }

    sort(input.begin(), input.end());

    //만들 수 있는 모든 숫자를 확인한다.
    for (int num = 1; num <= N; num++)
        go(0, 0, num); //index, cnt, 더 할 숫자의 수

    //
    for (int i = 1; i < 2000000; i++)
    {
        if (res_check[i] == false)
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}