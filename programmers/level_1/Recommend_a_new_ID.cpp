#include <string>
#include <vector>

using namespace std;

void Step_1_2(string &str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        char C = str[i];

        if ('A' <= C && C <= 'Z')
            temp += tolower(C);
        else if (('a' <= C && C <= 'z') || ('0' <= C && C <= '9') || C == '-' || C == '_' || C == '.') //2단계
            temp += C;
    }
    str = temp;
}
void Step_3(string &str)
{
    string temp = "";
    temp += str[0];
    for (int i = 1; i < str.length(); i++) //3단계
    {
        if (str[i] == '.' && str[i] == str[i - 1])
            continue;
        temp += str[i];
    }
    str = temp;
}
void Step_4(string &str)
{
    if (str.length() == 0)
        return;
    if (str[0] == '.')
        str = str.substr(1);
    if (str.length() >= 1 && str[str.length() - 1] == '.')
        str = str.substr(0, str.length() - 1);
}

void Step_5(string &str)
{
    if (str.length() == 0)
        str = "a";
}

void Step_6(string &str)
{
    if (str.length() >= 16)
        str = str.substr(0, 15);

    Step_4(str); //마지막이 .인지 확인
}

void Step_7(string &str)
{
    if (str.length() <= 2)
        while (str.length() != 3)
            str += str[str.length() - 1];
}

string solution(string new_id)
{
    string answer = new_id;

    Step_1_2(answer);
    Step_3(answer);
    Step_4(answer);
    Step_5(answer);
    Step_6(answer);
    Step_7(answer);

    return answer;
}