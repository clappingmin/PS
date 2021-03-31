#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int now_l = 10, now_r = 12; //*, #

    for (int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i];
        if (num == 0)
            num = 11;

        if (num % 3 == 1) //1,4,7
        {
            answer += "L";
            now_l = num;
        }
        else if (num != 0 && num % 3 == 0) //3,6,9
        {
            answer += "R";
            now_r = num;
        }
        else //2,4,8,0
        {
            int rdiff = abs(now_r - num);
            int ldiff = abs(now_l - num);

            int leftDist = (ldiff / 3) + (ldiff % 3);
            int rightDist = (rdiff / 3) + (rdiff % 3);

            if (rightDist < leftDist)
            {
                answer += "R";
                now_r = num;
            }
            else if (rightDist > leftDist)
            {
                answer += "L";
                now_l = num;
            }
            else
            {
                if (hand == "right")
                {
                    answer += "R";
                    now_r = num;
                }
                else if (hand == "left")
                {
                    answer += "L";
                    now_l = num;
                }
            }
        }
    }
    return answer;
}