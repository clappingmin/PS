#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 100 + 1

using namespace std;

int n, m;
vector<pair<int, int>> light[MAX][MAX];
int cnt = 1;
bool visit[MAX][MAX];
bool room[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
	queue<pair<int, int>> q;
	visit[1][1] = true;
	room[1][1] = true;
	q.push({1, 1});

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < light[x][y].size(); i++) //불 켜기
		{
			int tmp_x = light[x][y][i].first;
			int tmp_y = light[x][y][i].second;

			if (!room[tmp_x][tmp_y])
			{
				room[tmp_x][tmp_y] = true;
				cnt++;
			}
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n)
				continue;

			if (visit[nx][ny]||!room[nx][ny])	//방문했거나 불이 켜져있지 않으면
				continue;

			q.push({nx, ny});
			visit[nx][ny] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, a, b;

		cin >> x >> y >> a >> b;
		light[x][y].push_back({a, b});
	}

	int light_room = cnt;
	while (true)
	{
		memset(visit, false, sizeof(visit));
		bfs();

		if (light_room == cnt)
		{
			cout << cnt << '\n';
			break;
		}
		light_room = cnt;
	}

	return 0;
}