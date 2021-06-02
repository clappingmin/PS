#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n, k, l; //보드 크기, 사과 개수, 뱀 변환 횟수
int map[100][100];
queue<pair<int, char>> cmd;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int Turn_snake(int d, char c)
{
	if (c == 'D') //오른쪽
	{
		if (d == 0)
			return 1;
		else if (d == 1)
			return 2;
		else if (d == 2)
			return 3;
		else if (d == 3)
			return 0;
	}
	else if (c == 'L')
	{
		if (d == 0)
			return 3;
		else if (d == 1)
			return 0;
		else if (d == 2)
			return 1;
		else if (d == 3)
			return 2;
	}
}

void Solution()
{
	deque<pair<int, int>> snake;
	snake.push_back({0, 0});
	int d = 0; //시작 뱀 방향: 오른쪽
	int time = 0;
	map[0][0] = 2;

	while (true)
	{
		time++;

		int x = snake.front().first;
		int y = snake.front().second;

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == 2)
			break;

		if (map[nx][ny] == 1) //사과일 경우
		{
			snake.push_front({nx, ny});
			map[nx][ny] = 2;
		}
		else if (map[nx][ny] == 0) //빈공간 일 경우
		{
			map[nx][ny] = 2;
			snake.push_front({nx, ny});
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		if (!cmd.empty())
		{
			if (time == cmd.front().first)
			{
				d = Turn_snake(d, cmd.front().second);
				cmd.pop();
			}
		}
	}
	cout << time << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;

		map[x - 1][y - 1] = 1; //사과 좌표
	}

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		int x;
		char c;

		cin >> x >> c;

		cmd.push({x, c});
	}
	Solution();

	return 0;
}