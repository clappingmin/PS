#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int n, k;
int sis[MAX + 1];
bool check[MAX + 1];

int bfs() {
	
	queue<int> q;
	q.push(n);

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		if (x == k) { //도착했다.
			return sis[k];
		}

		if (2 * x <= MAX && sis[2 * x] == 0 && check[2*x] == false) {
			sis[2 * x] = sis[x];
			check[2 * x] = true;
			q.push(2 * x);
		}
		
		if (x - 1 >= 0 && sis[x - 1] == 0 && check[x-1] == false) {
			sis[x - 1] = sis[x] + 1;
			check[x - 1] = true;
			q.push(x - 1);
		}

		if (x + 1 <= MAX && sis[x + 1] == 0 && check[x+1] == false) {
			sis[x + 1] = sis[x] + 1;
			check[x + 1] = true;
			q.push(x + 1);
		}


	}
}

int main() 
{
	scanf("%d%d", &n, &k);
	printf("%d",bfs());
}