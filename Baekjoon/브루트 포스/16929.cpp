#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char map[50][50];
int dist[50][50];
bool check[50][50];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool DFS(int x, int y, int cnt)
{
	if (check[x][y])
	{
		if (cnt - dist[x][y] >= 4)
			return true;
		else
			return false;
	}
	dist[x][y] = cnt;
	check[x][y] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		if (map[nx][ny] != map[x][y])
			continue;

		if (DFS(nx, ny, cnt + 1))
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	string res = "No";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!check[i][j])
			{
				if (DFS(i, j, 0))
				{
					res = "Yes";
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j];
		}
		cout << '\n';
	}
	cout << res << '\n';
	return 0;
}