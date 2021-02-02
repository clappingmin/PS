#define MAX 987654321
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char arr[100][100];
int check[100][100][4];		//현 지점까지 필요한 거울의 최소 수, [4]: 직전에 어떤 방향에서 왔는지
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int row, col, sx = -1, sy;
struct info {
	int x, y, dir;
};
info tmp;

int main() {
	cin >> col >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			for(int k=0;k<4;k++)
				check[i][j][k] = MAX;
			if (arr[i][j] == 'C' && sx == -1) {
				sx = j;
				sy = i;
				arr[i][j] = '.';
				for (int k = 0; k < 4; k++)
					check[i][j][k] = 0;
			}
		}
	queue<info> q;
	tmp.x = sx;
	tmp.y = sy;
	for (int k = 0; k < 4; k++) {
		tmp.dir = k;
		q.push(tmp);
	}
	int result = MAX;
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cd = q.front().dir;
		q.pop();
		if (arr[cy][cx] == 'C') {
			result = min(result, check[cy][cx][cd]);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < col && ny<row && arr[ny][nx] != '*') {
				if (i != cd && check[ny][nx][i] > check[cy][cx][cd] + 1) {			//거울 사용
					check[ny][nx][i] = check[cy][cx][cd] + 1;
					tmp.x = nx;
					tmp.y = ny;
					tmp.dir = i;
					q.push(tmp);
				}
				else if (i == cd && check[ny][nx][cd] > check[cy][cx][cd]) {		//거울 사용x
					check[ny][nx][cd] = check[cy][cx][cd];
					tmp.x = nx;
					tmp.y = ny;
					tmp.dir = i;
					q.push(tmp);
				}
			}
		}
	}
	cout << result;
	system("pause");
	return 0;
}