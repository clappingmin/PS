#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<int> v(26, -1);

    int cnt = 0;
    for (char ch : str)
    {
        int tmp = ch - 97;

        if (v[tmp] == -1)
            v[tmp] = cnt;
        cnt++;
    }
    for (int i = 0; i < 26; i++)
        printf("%d ", v[i]);

    return 0;
}