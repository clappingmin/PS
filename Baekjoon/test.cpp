#include <iostream>
#include <vector>

using namespace std;

bool check(string res)
{
    int tmp = 0;

    res.erase(remove(res.begin(),res.end(),' '),res.end());

    cout<<res;
    return true;

}
void go(vector<int> &num, int sum,int index, string res)
{
    if(index == num.size())
    {
        if(check(res))
    }

    //+일 경우
    go(num,sum+)
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

string res = "1-2 3-4 5+6 7";

    res.erase(remove(res.begin(),res.end(),' '),res.end());

cout<<res<<'\n';

    return 0;
}