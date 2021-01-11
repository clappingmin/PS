#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alphabet1[26], alphabet2[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res =0;
    string s1, s2;

    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++)
        alphabet1[s1[i] - 'a']++;

    for (int i = 0; i < s2.size(); i++)
        alphabet2[s2[i] - 'a']++;

    
    for(int i=0;i<26;i++)
        res+=abs(alphabet1[i]-alphabet2[i]);

    cout<< res;
    
    return 0;
}