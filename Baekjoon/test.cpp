#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(const pair<double, int> &a, const pair<double, int> &b)
{
	if (a.first == b.first)
	{
		if (b.second > a.second)
			return true;
		else
			return false;
	}
	else if (a.first > b.first)
		return true;
	else
		return false;
}
vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;
	vector<pair<double, int>> fail(N + 1);

	sort(stages.begin(), stages.end());

	for (int i = 0; i < stages.size(); i++)
	{
		int st_num = stages[i]; //못 깬 스테이지

		if (st_num <= N)
			fail[st_num].first += 1;
	}

	double player = stages.size();

	for (int i = 1; i <= N; i++)
	{
		fail[i].second = i;
		int num = fail[i].first;

		if (num == 0)
		{
			fail[i].first = 0;
			continue;
		}

		fail[i].first = (double)num / player;
		player -= num;
	}

	sort(fail.begin() + 1, fail.end(), compare);

	for (int i = 1; i <= N; i++)
	{
		answer.push_back[fail[i].second];
	}
	return answer;
}