#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int n, m;
char map[20][20];
vector<pair<int, int>> coin;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool check[20][20];
int res = INT_MAX;

bool range_over(int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= n || ny >= m)
		return true;
	return false;
}

void move(int x1, int y1, int x2, int y2, int cnt, int dir)
{
	if (res < cnt)
		return;
	if (cnt > 10)
	{
		res = min(res, cnt);
		return;
	}

	int nx1 = x1 + dx[dir];
	int ny1 = y1 + dy[dir];
	int nx2 = x2 + dx[dir];
	int ny2 = y2 + dy[dir];

	if (range_over(nx1, ny1) == true && range_over(nx2, ny2) == true)
		return;
	else if (range_over(nx1, ny1) == false && range_over(nx2, ny2) == true)
	{
		res = min(res, cnt);
		return;
	}
	else if (range_over(nx1, ny1) == true && range_over(nx2, ny2) == false)
	{
		res = min(res, cnt);
		return;
	}
	if (map[nx1][ny1] == '#')
	{
		nx1 = x1;
		ny1 = y1;
	}
	if (map[nx2][ny2] == '#')
	{
		nx2 = x2;
		ny2 = y2;
	}
	for (int i = 0; i < 4; i++)
	{
		move(nx1, ny1, nx2, ny2, cnt + 1, i);
	}
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

			if (map[i][j] == 'o')
			{
				coin.push_back({i, j});
			}
		}
	}

	for (int dir = 0; dir < 4; dir++)
	{
		move(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 1, dir);
	}

	if (res > 10)
		cout << -1 << '\n';
	else
		cout << res << '\n';

	return 0;
}