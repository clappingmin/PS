#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[50][50];
int check_map[50][50];
vector<pair<int, int>> virus;
bool check_virus[10];
int res = 987654321;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int empty_cnt = 0;

int count_virus()
{
	queue<pair<int, int>> q;
	int time = 0;
	int cnt = 0;
	memset(check_map, -1, sizeof(check_map));

	for (int i = 0; i < 10; i++)
	{
		if (check_virus[i])
		{
			q.push(virus[i]);
			check_map[virus[i].first][virus[i].second] = 0;
		}
	}

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

			if (map[nx][ny] == 1 || check_map[nx][ny] != -1)
				continue;

			check_map[nx][ny] = check_map[x][y] + 1;
			q.push({nx, ny});

			if (map[nx][ny] == 0)
			{
				cnt++;
				time = check_map[nx][ny];
			}
		}

		if (empty_cnt == cnt)
			return time;
	}
	return 987654321;
}

void choice_virus(int idx, int cnt)
{
	if (cnt == m)
	{
		res = min(res, count_virus());
	}
	for (int i = idx; i < virus.size(); i++)
	{
		if (check_virus[i])
			continue;

		check_virus[i] = true;
		choice_virus(i, cnt + 1);
		check_virus[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				virus.push_back({i, j});

			else if (map[i][j] == 0)
				empty_cnt++;
		}
	}

	choice_virus(0, 0); //1.활성할 바이러스 선택

	if (res == 987654321)
		cout << -1 << '\n';
	else
		cout << res << '\n';

	return 0;
}