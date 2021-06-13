#include <iostream>
#include <algorithm>
#define MAX 10000 + 1

using namespace std;

struct Node
{
    int left, right;
    int order, depth;
};

int n;
Node a[MAX];
bool check_child[MAX];
int order = 1;
int left_order[MAX];
int right_order[MAX];

void inorder(int node, int depth)
{
    if (node == -1)
        return;

    inorder(a[node].left, depth + 1);
    a[node].order = order++;
    a[node].depth = depth;
    inorder(a[node].right, depth + 1);
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
        int order = a[i].order;
        int depth = a[i].depth;

        if (left_order[depth] == 0)
            left_order[depth] = order;
        else
            left_order[depth] = min(left_order[depth], order);

        right_order[depth] = max(right_order[depth], order);

        max_depth = max(max_depth, depth);
    }

    int res_order = 0, res_level = 0;

    for (int i = 1; i <= max_depth; i++)
    {
        if (res_order < right_order[i] - left_order[i] + 1)
        {
            res_order = right_order[i] - left_order[i] + 1;
            res_level = i;
        }
    }
    cout << res_level << " " << res_order << '\n';

    return 0;
}