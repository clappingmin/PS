#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
bool check[101][101];
bool light[101][101];
vector<pair<int, int>> v[101][101];
int cnt = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
	queue<pair<int, int>> q;
	q.push({1, 1});
	light[1][1] = true;
	check[1][1] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < v[x][y].size(); i++)
		{
			int temp_x = v[x][y][i].first;
			int temp_y = v[x][y][i].second;

			if (!light[temp_x][temp_y])
			{
				light[temp_x][temp_y] = true;
				cnt++;
			}
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n)
				continue;

			if (check[nx][ny] || !light[nx][ny])
				continue;
			
			check[nx][ny] = true;
			q.push({nx,ny});
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
		v[x][y].push_back({a, b});
	}

	cnt = 1; 

	while(true)
	{
		int before_cnt = cnt;
		memset(check,false,sizeof(check));
		bfs();

		if(before_cnt == cnt)
		break;

	}

	cout<<cnt<<'\n';

	return 0;
}