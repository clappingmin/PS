#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    getline(cin, s);

    for (char ch : s)
    {
        if ('A' <= ch && ch <= 'Z')
        {
            int tmp = ch + 13;

            if (tmp > 'Z')
                tmp -= 26;
            printf("%c", tmp);
        }
        else if ('a' <= ch && ch <= 'z')
        {
            int tmp = ch + 13;

            if (tmp > 'z')
                tmp -= 26;
            printf("%c", tmp);
        }
        else
            printf("%c", ch);
    }
    return 0;
}