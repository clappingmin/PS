#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    string temp = "";
    for (int i = 0; i < new_id.length(); i++)
    {
        char C = new_id[i];
        
        if ('A' <= C && C <= 'Z') //1단계
            temp += tolower(C);
        else if (('a' <= C && C <= 'z') || ('0' <= C && C <= '9') || C == '-' || C == '_' || C == '.')//2단계
            temp += C;
    }

    string temp2 ="";
    temp2 += temp[0];
    for (int i = 1; i < temp.length(); i++) //3단계
    {
        if (temp[i] == '.' && temp[i] == temp[i - 1])
            continue;
        temp2 += temp[i];
    }

    if (Str[0] == '.') Str = Str.substr(1);
    if (Str.length() >= 1 && Str[Str.length() - 1] == '.') Str = Str.substr(0, Str.length() - 1);



    return temp2;
}

int main()
{
    string s = "...!@BaT#*..y.abcdefghijklm";

    cout<< solution(s)<<'\n';

    return 0;
}