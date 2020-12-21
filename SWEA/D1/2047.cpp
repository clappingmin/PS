#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) >= 'a' && str.at(i) <= 'z')
            str[i] = str[i] - 32;
    }

    cout << str << "\n";

    return 0;
}