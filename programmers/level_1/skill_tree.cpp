#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i =0;i<skill_trees.size();i++)
    {
        bool flag = true;
        int idx =0;
        
        for(int j=0;j<skill_trees[i].size();j++)
        {
            int cur = skill.find(skill_trees[i][j]);
            
            if (cur == -1)
                continue;
            else
                if(idx++ != cur)
                {
                    flag = false;
                    break;
                }
        }
        if(flag == true)
            answer+=1;
    }
    return answer;
}