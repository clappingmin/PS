#include <string>
#include <vector>

using namespace std;

int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weeks[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b)
{
    string answer = "";

    int temp = -1;
    for (int i = 0; i < a - 1; i++)
        temp += month[i];
    temp += b;

    answer = weeks[temp % 7];
    return answer;
}