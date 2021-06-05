#include <iostream>
#include <string>
#include <queue>

using namespace std;

int r, c;
int swan_index[2][2];
int day = 0;
char map[1501][1501];
bool visited[1501][1501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> swan;
queue<pair<int, int>> swan_ice;
queue<pair<int, int>> water;
queue<pair<int, int>> water_ice;

void melting_ice()
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

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;

			if (map[nx][ny] == 'X')
			{
				map[nx][ny] = '.';
				water_ice.push({nx, ny});
			}
		}
	}
}
bool meet_swan()
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

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;

			if (visited[nx][ny])
				continue;

			if (map[nx][ny] == '.')
			{
				visited[nx][ny] = true;
				swan.push({nx, ny});
			}
			else if (map[nx][ny] == 'X')
			{
				visited[nx][ny] = true;
				swan_ice.push({nx, ny});
			}
			else if (map[nx][ny] == 'L')
			{
				visited[nx][ny] = true;
				return true;
			}
		}
	}
	return false;
}

void memset_q()
{
	while (!water_ice.empty())
		water_ice.pop();
	while (!swan_ice.empty())
		swan_ice.pop();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	int n = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];

            if (map[i][j] != 'X')
				water.push({i, j});
                
			if (map[i][j] == 'L')
			{
				swan_index[n][0] = i;
				swan_index[n][1] = j;
				n++;
			}
		}
	}
	swan.push({swan_index[0][0], swan_index[0][1]});
	visited[swan_index[0][0]][swan_index[0][1]] = true;

	while (true)
	{
		if (meet_swan()) //1.백조가 만나는지 확인
		{
			cout << day << '\n';
			break;
		}
		melting_ice();	//2.얼음 녹이기
		water = water_ice;
		swan = swan_ice;
		memset_q();
		day++;
	}

	return 0;
}