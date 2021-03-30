#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";

    int a = s.size();

    if (a % 2 == 1)
        answer += s[a / 2];
    else
    {
        answer += s[a / 2 - 1];
        answer += s[a / 2];
    }

    return answer;
}