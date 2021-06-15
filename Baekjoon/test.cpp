#include <iostream>
#include <algorithm>
#define MAX 10000 + 1

using namespace std;

struct Node
{
	int left, right;
	int depth, order;
};

int n;
Node a[MAX];
bool check_child[MAX];
int order = 1;
int left_ord[MAX];
int right_ord[MAX];

void inorder(int x, int depth)
{
	if (x == -1)
		return;

	inorder(a[x].left, depth + 1);
	a[x].depth = depth;
	a[x].order = ++order;
	inorder(a[x].right, depth + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, z;

		cin >> x >> y >> z;

		a[x].left = y;
		a[x].right = z;

		if (y != -1)
			check_child[y] = true;

		if (z != -1)
			check_child[z] = true;
	}

	int root = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!check_child[i])
		{
			root = i;
			break;
		}
	}

	inorder(root, 1);
	int max_depth = 0;

	for (int i = 1; i <= n; i++)
	{
		int now_depth = a[i].depth;
		int now_order = a[i].order;

		if (left_ord[now_depth])
			left_ord[now_depth] = min(left_ord[now_depth], now_order);
		else
			left_ord[now_depth] = now_order;

		right_ord[now_depth] = max(right_ord[now_depth], now_order);

		max_depth = max(max_depth, now_depth);
	}

	int res_order = 0, res;

	for (int i = 1; i <= max_depth; i++)
	{
		if (res_order < right_ord[i] - left_ord[i] + 1)
		{
			res_order = right_ord[i] - left_ord[i] + 1;
			res = i;
		}
	}
	cout << res << " " << res_order << '\n';

	return 0;
}