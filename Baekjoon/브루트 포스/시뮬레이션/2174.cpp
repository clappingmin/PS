#include <cstdio>

struct robot
{
    int x, y, z;
};

int A, B, N, M;
int w[101][101];
robot r[101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool solve(int id, char direct, int cnt)
{
    int &x = r[id].x, &y = r[id].y, &z = r[id].z;
    w[x][y] = 0;
    while (cnt--)
    {
        if (direct == 'L')
            z = (z + 1) % 4;
        else if (direct == 'R')
            z = (z + 3) % 4;
        else
        {
            x += dx[z], y += dy[z];
            if (x < 1 || x > B || y < 1 || y > A)
            {
                printf("Robot %d crashes into the wall\n", id);
                return true;
            }
            if (w[x][y])
            {
                printf("Robot %d crashes into robot %d\n", id, w[x][y]);
                return true;
            }
        }
    }
    w[x][y] = id;
    return false;
}

int main()
{
    scanf("%d %d", &A, &B);
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        int x, y;
        char z;
        scanf("%d %d %c", &x, &y, &z);
        w[y][x] = i;
        if (z == 'S')
            z = 0;
        else if (z == 'E')
            z = 1;
        else if (z == 'N')
            z = 2;
        else
            z = 3;
        r[i] = {y, x, z};
    }
    bool crash = false;
    while (M--)
    {
        int id, cnt;
        char direct;
        scanf("%d %c %d", &id, &direct, &cnt);
        if (!crash)
            crash = solve(id, direct, cnt);
    }
    if (!crash)
        printf("OK\n");
    return 0;
}
