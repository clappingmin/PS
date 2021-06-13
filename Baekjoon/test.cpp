#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3000 + 1

using namespace std;

int n;
vector<int> station[MAX];
bool visited[MAX];
bool cycle_station[MAX];
bool cycle;

int bfs(int x)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({x, 0});
	visited[x] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cycle_station[cur])
			return cnt;

		for (int i = 0; i < station[cur].size(); i++)
		{
			int next = station[cur][i];

			if (visited[next])
				continue;

			visited[next] = true;
			q.push({next, cnt + 1});
		}
	}
}

void dfs(int cur, int start, int cnt)
{
	if (cur == start && cnt >= 2)
	{
		cycle = true;
		return;
	}
	visited[cur] = true;

	for (int i = 0; i < station[cur].size(); i++)
	{
		int next = station[cur][i];

		if (!visited[next]) //방문하지 않은 역일 경우
		{
			dfs(next, start, cnt + 1);
		}
		else //방문한 역일 경우
		{
			if (next == start && cnt >= 2)
				dfs(next, start, cnt);
			
		}
		if (cycle==true)
			return;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		cycle = false;

		int start = i;
		dfs(i, start, 0);

		if (cycle==true)
			cycle_station[i] = true;
	}

	vector<int> res;

	for (int i = 1; i <= n; i++)
	{
		if (cycle_station[i])
			res.push_back(0);
		else
			res.push_back(bfs(i));
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << "\n";
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

		station[a].push_back(a);
		station[b].push_back(b);
	}

	solution();

	return 0;
}