#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n;
int mi = INT_MAX;
int ma = INT_MIN;
vector<int> num;

void dfs(int idx, int add, int sub, int mul, int div, int sum)
{
    if (idx == n - 1)
    {
        mi = min(mi, sum);
        ma = max(ma, sum);
        return;
    }

    if (add != 0)
        dfs(idx + 1, add - 1, sub, mul, div, sum + num[idx + 1]);
    if (sub != 0)
        dfs(idx + 1, add, sub - 1, mul, div, sum - num[idx + 1]);
    if (mul != 0)
        dfs(idx + 1, add, sub, mul - 1, div, sum * num[idx + 1]);
    if (div != 0)
    {
        if (sum < 0)
        {
            sum *= -1;
            sum /= num[idx + 1];
            sum *= -1;
            dfs(idx + 1, add, sub, mul, div - 1, sum);
        }
        else
            dfs(idx + 1, add, sub, mul, div - 1, sum / num[idx + 1]);
    }
}

int main()
{

    int i, temp;
    vector<int> op;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        num.push_back(temp);
    }
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &temp);
        op.push_back(temp);
    }

    dfs(0, op[0], op[1], op[2], op[3], num[0]);
    printf("%d\n%d\n", ma, mi);

    return 0;
}