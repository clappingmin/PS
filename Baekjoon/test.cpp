#include <iostream>
#include <queue>

using namespace std;

int r, c;
char map[1500][1500];
bool check[1500][1500];
queue<pair<int, int>> water;
queue<pair<int,int>> water_ice;
queue<pair<int,int>> swan;
queue<pair<int,int>> swan_ice;
int swan_idx[2][2];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void water_bfs()
{
	while(!water.empty())
	{
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for(int dir =0; dir<4;dir++)
		{
			int nx = x+ dx[dir];
			int ny = y +dy[dir];

			if(nx<0||ny<0||nx>=r||ny>=c)
			continue;

			if(map[nx][ny]=='X')
			{
				map[nx][ny]='.';
				water_ice.push({nx,ny});
			}
		}
	}
}
bool swan_bfs()
{
	while(!swan.empty())
	{
		int x = swan.front().first;
		int y = swan.front().second;
		swan.pop();

		for(int dir = 0; dir<4;dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx<0||ny<0||nx>=r||ny>=c)
			continue;

			if(check[nx][ny])
			continue;

			if(map[nx][ny]=='.')
			{swan.push({nx,ny});
			check[nx][ny] = true;
			}

			else if(map[nx][ny]=='X')
			{
				swan_ice.push({nx,ny});
				check[nx][ny] = true;
			}
			else if(map[nx][ny]=='L')
			{
				return true;
			}

		}
	}
	return false;
}
void memset_q()
{
	while(!swan_ice.empty())
	swan_ice.pop();
	while(!water_ice.empty())
	water_ice.pop();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	int n = 0, day=0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 'X')
				water.push({i, j});
			if (map[i][j] == 'L')
			{
				swan_idx[n][0] = i;
				swan_idx[n][1] = j;
				n++;
			}
		}
	}
	swan.push({swan_idx[0][0],swan_idx[0][1]});
	check[swan_idx[0][0]][swan_idx[0][1]] = true;

	while(true)
	{
		//1. 만났는지 확인
		if (swan_bfs())
		{
			cout<<day<<'\n';
			break;
		}
		day++;
		water_bfs();	//2.얼음 녹이기
		water = water_ice;
		swan = swan_ice;
		memset_q();
		
	}


	return 0;
}