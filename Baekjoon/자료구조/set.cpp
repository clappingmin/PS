//set 특징
//1. 숫자든 문자든 중복을 없엔다.
//2. 삽입하는 순서에 상관없이 정렬되서 입력이 된다.

#include <iostream>
#include <Set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> s;

    s.insert(40);
    s.insert(10);
    s.insert(80);
    s.insert(30);
    s.insert(70);
    s.insert(60);
    s.insert(20);
    s.insert(50);
    s.insert(10);

    int arr[] = {2, 5, 6, 4, 1, 8};

    set<int> s1(s.begin(), s.end());
    set<int> s2(arr, arr + 6);

    set<int>::iterator iter;

    for (iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << " ";
    cout << "\n";

    //존재 하는 원소 찾기
    iter = s.find(30);
    if (iter != s.end())
    {
        cout << *iter << " : OK! " << endl;
    }
    else
    {
        cout << "Not OK! " << endl;
    }

    //존재 하지 않는 원소 찾기
    iter = s.find(333);
    if (iter != s.end())
    {
        cout << *iter << " : OK! " << endl;
    }
    else
    {
        cout << "Not OK! " << endl;
    }

    return 0;
}