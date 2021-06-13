#include <iostream>

using namespace std;

struct Node
{
    int left;
    int right;
};
Node node[50];

void preorder(int x)
{
    if (x == -1)
        return;

    cout << (char)(x + 'A');
    preorder(node[x].left);
    preorder(node[x].right);
}
void inorder(int x)
{
    if (x == -1)
        return;

    inorder(node[x].left);
    cout << (char)(x + 'A');
    inorder(node[x].right);
}
void postorder(int x)
{
    if (x == -1)
        return;

    postorder(node[x].left);
    postorder(node[x].right);
    cout << (char)(x + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        char x, y, z;

        cin >> x >> y >> z;

        x = x - 'A';

        if (y == '.')
            node[x].left = -1;
        else
            node[x].left = y - 'A';

        if (z == '.')
            node[x].right = -1;
        else
            node[x].right = z - 'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
}