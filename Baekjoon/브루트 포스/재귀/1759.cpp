#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c; //password 길이, 입력 받을 알파벳 개수

bool check(string &pass)
{
    int mo = 0, ja = 0;

    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] == 'a' || pass[i] == 'i' || pass[i] == 'e' || pass[i] == 'o' || pass[i] == 'u')
            mo++;
        else
            ja++;
    }
    if (mo >= 1 && ja >= 2)
        return true;
    else
        return false;
}

void makepass(vector<char> &alpha, string pass, int i)
{
    if (pass.length() == l)
    {
        if (check(pass))
        {
            cout << pass << '\n';
        }
        return;
    }
    if (i >= alpha.size())
        return;
    makepass(alpha, pass + alpha[i], i + 1); //i번째 알파벳을 선택한 경우
    makepass(alpha, pass, i + 1);            //i번째 알파벳을 선택하지 않은 경우
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<char> alpha;

    cin >> l >> c;

    for (int i = 0; i < c; i++)
    {
        char c;
        cin >> c;
        alpha.push_back(c);
    }

    sort(alpha.begin(), alpha.end());
    makepass(alpha, "", 0);

    return 0;
}