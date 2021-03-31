#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer(n);
    deque<string> tmp(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] % 2 == 1 || arr2[i] % 2 == 1)
                tmp[i] += "#";

            else
                tmp[i] += " ";

            arr1[i] /= 2;
            arr2[i] /= 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            answer[i] += tmp[i][j];
        }
    }

    return answer;
}