#include <iostream>
#include <string>

using namespace std;

int arr[26];
int max1 = 0, max2 = 0;
char res;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            int num = s[i] - 'a';
            arr[num]++;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            int num = s[i] - 'A';
            arr[num]++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= max1)
        {
            max2 = max1;
            max1 = arr[i];
            res = 'A' + i;
        }
    }

    if (max1 == max2)
        cout << '?' << '\n';
    else
        cout << res << '\n';

    return 0;
}