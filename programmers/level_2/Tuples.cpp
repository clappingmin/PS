#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check_num[100001];
vector<pair<int, int>> check_size;

vector<int> solution(string s)
{
    vector<int> answer;
    queue<int> q[501];
    int idx = 0;
    string temp = "";
    bool check_end = false;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            check_end = false;
        }

        else if (s[i] == '}')
        {
            q[idx].push(stoi(temp));
            temp = "";
            check_end = true;
            check_size.push_back({q[idx].size(), idx});
        }

        else if (s[i] == ',')
        {
            if (check_end == true)
            {
                idx += 1;
            }
            else if (check_end == false)
            {
                q[idx].push(stoi(temp));
                temp = "";
            }
        }

        else if ('0' <= s[i] && s[i] <= '9')
        {
            temp += s[i];
        }
    }

    sort(check_size.begin(), check_size.end());

    for (int i = 0; i <= idx; i++)
    {
        int index = check_size[i].second;

        for (int j = 0; j < q[index].size(); j++)
        {
            int t = q[index].front();

            if (check_num[t] == false)
            {
                check_num[t] = true;
                answer.push_back(t);
            }
            q[index].pop();
            q[index].push(0);
        }
    }

    return answer;
}