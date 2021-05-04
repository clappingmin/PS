#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int &n, vector<int> &stones, int &k)
{
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - n <= 0)
            cnt++;
        else
            cnt = 0;
        if (cnt >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int Start = 1;
    int End = *max_element(stones.begin(), stones.end());
    while (Start <= End)
    {
        int mid = (Start + End) / 2;
        if (binarySearch(mid, stones, k))
            End = mid - 1; //못건너면 사람 줄여서 줄인 사람은 건널 수 있는지 알아본다.
        else
            Start = mid + 1; //건너면 사람 늘려서 더 건널 수 있는지 알아본다.
    }
    return Start;
}