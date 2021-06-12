#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3000 + 1

using namespace std;

int n;
vector<int> station[MAX];
bool cycle;
bool visit[MAX];
bool check_cycle_station[MAX];

int bfs(int x)
{
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({x, 0});
	visit[x] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (check_cycle_station[cur])
			return cnt;

		for (int i = 0; i < station[cur].size(); i++)
		{
			int next = station[cur][i];

			if (!visit[next])
			{
				visit[next] = true;
				q.push({next, cnt + 1});
			}
		}
	}
}

void dfs(int cur, int start, int cnt) //현재역, 시작역, 역 개수
{
	if (cur == start && cnt >= 2)
	{
		cycle = true;
		return;
	}

	visit[cur] = true;

	for (int i = 0; i < station[cur].size(); i++)
	{
		int next = station[cur][i];

		if (!visit[next])
			dfs(next, start, cnt + 1);
		else
		{
			if (next == start && cnt >= 2)
				dfs(next, start, cnt);
		}

		if (cycle == true)
			return;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		memset(visit, false, sizeof(visit));
		cycle = false;

		int start = i;
		dfs(i, start, 0);

		if (cycle == true)
			check_cycle_station[i] = true;
	}

	vector<int> res;

	for (int i = 1; i <= n; i++)
	{
		if (check_cycle_station[i])
		{
			res.push_back(0);
			continue;
		}

		res.push_back(bfs(i));
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		station[a].push_back(b);
		station[b].push_back(a);
	}

	solution();

	return 0;
}