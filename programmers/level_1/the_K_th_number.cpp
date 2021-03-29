#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        int I = commands[i][0];
        int J = commands[i][1];
        int K = commands[i][2];

        vector<int>temp;

        for (int j = I-1; j < J; j++)
            temp.push_back(array[j]);   //1.

        sort(temp.begin(), temp.end()); //2.

        answer.push_back(temp[K-1]);    //3.
        
    }

    return answer;
}