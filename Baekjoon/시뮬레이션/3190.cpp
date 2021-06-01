#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int N, K, L;
int map[101][101];
queue<pair<int, char>> cmd;
bool check = true;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int Turn_snake(int d, char c)
{
	if (c == 'D') //오른쪽일 경우
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
	else if (c == 'L') //왼쪽일 경우
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
	int d = 0;
	snake.push_back({0, 0});
	map[0][0] = 2; //뱀 표시
	int time = 0;

	int cmd_time = cmd.front().first;
	char cmd_dir = cmd.front().second;
	cmd.pop();

	while (true)
	{
		time++;

		int nx = snake.front().first + dx[d];
		int ny = snake.front().second + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 2)
			break;

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = 2;
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
			snake.push_front({nx, ny});
		}

		else if (map[nx][ny] == 1)
		{
			map[nx][ny] = 2;
			snake.push_front({nx, ny});
		}
		
		if (time == cmd_time)
		{
			d = Turn_snake(d, cmd_dir);
			if (!cmd.empty())
			{
				cmd_time = cmd.front().first;
				cmd_dir = cmd.front().second;
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

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1; //사과
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		cmd.push({x, c});
	}
	Solution();

	return 0;
}
