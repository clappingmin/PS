#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool alphabet[27];
int n, k; //단어 수, 배울 수 있는 알파벳 수
vector<string> word;
int res = 0;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int count_word()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < word[i].size(); j++)
        {
            int temp = word[i][j] - 'a';

            if (!alphabet[temp])
            {
                check = false;
                break;
            }
        }
        if (check)
            cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt)
{
    if (cnt == k)
    {
        res = max(res, count_word()); //읽을 수 있는 단어 세기
        return;
    }
    for (int i = idx; i < 26; i++)
    {
        if (alphabet[i])
            continue;

        alphabet[i] = true;
        dfs(i, cnt + 1);
        alphabet[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        word.push_back(s);
    }

    if (k < 5) //a,n,t,i,c
        cout << res << '\n';

    else
    {
        alphabet['a' - 'a'] = true;
        alphabet['n' - 'a'] = true;
        alphabet['t' - 'a'] = true;
        alphabet['i' - 'a'] = true;
        alphabet['c' - 'a'] = true;

        k -= 5;

        dfs(0, 0);

        cout << res << '\n';
    }

    return 0;
}