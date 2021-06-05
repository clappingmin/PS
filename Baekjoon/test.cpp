#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX 1501

int R, C;
int Swan_index[2][2];
int Day = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> water;
queue<pair<int, int>> water_ice;
queue<pair<int, int>> swan;
queue<pair<int, int>> swan_ice;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool Swan_BFS()
{
	while (!swan.empty())
	{
		int x = swan.front().first;
		int y = swan.front().second;
		swan.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;

			if (visit[nx][ny])
				continue;

			if (map[nx][ny] == '.')
			{
				visit[nx][ny] = true;
				swan.push({nx, ny});
			}
			else if (map[nx][ny] == 'X')
			{
				visit[nx][ny] = true;
				swan_ice.push({nx, ny});
			}
			else if (map[nx][ny] == 'L')
			{
				visit[nx][ny] = true;
				return true;
			}
		}
	}
	return false;
}

void Water_BFS()
{
	while (!water.empty())
	{
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;

			if (map[nx][ny] == 'X')
			{
				map[nx][ny] = '.';
				water_ice.push({nx, ny});
			}
		}
	}
}

void memset_arr()
{
	while (!water_ice.empty())
		water_ice.pop();
	while (!swan_ice.empty())
		swan_ice.pop();
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main()
{
	init();
	cin >> R >> C;

	int n = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 'X')
				water.push(make_pair(i, j));
			if (map[i][j] == 'L')
			{
				Swan_index[n][0] = i;
				Swan_index[n][1] = j;
				n++;
			}
		}
	}

	swan.push(make_pair(Swan_index[0][0], Swan_index[0][1]));
	visit[Swan_index[0][0]][Swan_index[0][1]] = true;
	while (true)
	{
		if (Swan_BFS())
		{
			cout << Day;
			break;
		}
		Water_BFS();
		swan = swan_ice;
		water = water_ice;
		memset_arr();
		Day++;
	}

	return 0;
}