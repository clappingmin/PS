#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    getline(cin, str);

    while (1)
    {
        if (str.length() == 0)
            break;

        int cl = 0, sl = 0, n = 0, sp = 0; //대문자,소문자, 숫자, 공백

        for (char ch : str)
        {
            if ('A' <= ch && ch <= 'Z')
                cl++;
            else if ('a' <= ch && ch <= 'z')
                sl++;
            else if ('0' <= ch && ch <= '9')
                n++;
            else if (ch == ' ')
                sp++;
        }
        printf("%d %d %d %d\n", sl, cl, n, sp);
        getline(cin, str);
    }

    return 0;
}