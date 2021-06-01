#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

set<string> gems_name;
unordered_map<string, int> m;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2);

    int l = 0, r = 0;
    int len = (int)gems.size();

    answer[0] = 0;
    answer[1] = len - 1;

    for (int i = 0; i < gems.size(); i++)
        gems_name.insert(gems[i]); //보석 종류

    int gems_cnt = gems_name.size(); //보석 개수

    m[gems[0]]++; //첫번째 보석 포함
    while (1)
    {
        if (m.size() == gems_cnt)
        {
            if (answer[1] - answer[0] > r - l)
            {
                answer[0] = l;
                answer[1] = r;
            }
        }
    }

    return answer;
}