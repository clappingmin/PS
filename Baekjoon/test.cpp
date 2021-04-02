#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	queue<char> q;

	for (int j = skill.length() - 1; j >= 0; j--)
		q.push(skill[j]);

	for (int i =0;i<q.size();i++)
	cout<<q[i]<<'\n';

	for (int i = 0; i < skill_trees.size(); i++)
	{


		for (int j = 0; j < skill_trees[i].length(); i++)
		{
			if (skill_trees[i][j] == q.back())
				q.pop();
		}
		if (q.emplace())
			answer += 1;
	}
	return answer;
}