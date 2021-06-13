#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int map[100][100];
bool check[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist[100][100];
int res = 0;

int create_bridge(int label)
{
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == label)
			{
				q.push({i, j});
				check[i][j] = true;
			}
		}
	}

	int cnt = 0;

	while (!q.empty())
	{
		int island = q.size();

		for (int i = 0; i < island; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (map[nx][ny] != 0 || map[nx][ny] != label)
					return cnt;

				if (!check[nx][ny] && map[nx][ny] == 0)
				{
					q.push({nx, ny});
					check[nx][ny] = true;
				}
			}
		}
		cnt++;
	}
}

void labeling(int i, int j, int label)
{
	queue<pair<int, int>> q;
	check[i][j] = true;
	q.push({i, j});
	map[i][j] = label;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (map[nx][ny] == 0 || check[nx][ny])
				continue;

			map[nx][ny] = label;
			check[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int label = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j] && map[i][j] == 1)
			{
				labeling(i, j, label);
				label++;
			}
		}
	}

	for (int i = 1; i <= label; i++)
	{
		memset(check, false, sizeof(false));
		res = min(res, create_bridge(i));
	}

	cout << res << '\n';

	return 0;
}