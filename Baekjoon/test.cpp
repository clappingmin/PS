#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000 + 1

using namespace std;

int n;
vector<int> v[MAX];
int parents[MAX];
bool check[MAX];

void bfs()
{
	queue<int> q;
	q.push(1);
	check[1] = true;
	parents[1] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++)
		{
			int nx = v[x][i];

			if (check[nx])
				continue;

			parents[nx] = x;
			check[nx] = true;
			q.push(nx);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++)
		cout << parents[i] << '\n';

	return 0;
}