#include <iostream>
#include <algorithm>
#define MAX 10000 + 1

using namespace std;

struct Node
{
	int left, right;
	int order, depth; //열, 행
};

int n;
Node a[MAX];
bool check_child_node[MAX];
int order = 0;
int left_order[MAX], right_order[MAX];

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
			check_child_node[y] = true; //루트 노드를 찾기 위해 사용

		if (z != -1)
			check_child_node[z] = true;
	}

	int root;

	for (int i = 1; i <= n; i++)
	{
		if (!check_child_node[i])
		{
			root = i;
			break;
		}
	}

	inorder(root, 1);
	int max_depth = 0;

	for (int i = 1; i <= n; i++)
	{
		int now_order = a[i].order;
		int now_depth = a[i].depth;

		if (left_order[now_depth] == 0)
			left_order[now_depth] = now_order;
		else
			left_order[now_depth] = min(left_order[now_depth], now_order);

		right_order[now_depth] = max(right_order[now_depth] ,now_order);
		max_depth = max(max_depth, now_depth);
	}

	int res_level, res = 0;

	for (int i = 1; i <= max_depth; i++)
	{
		if (res < right_order[i] - left_order[i] + 1)
		{
			res = right_order[i] - left_order[i] + 1;
			res_level = i;
		}
	}

	cout << res_level << " " << res << '\n';

	return 0;
}