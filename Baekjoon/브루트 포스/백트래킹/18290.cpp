#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int arr[10][10];
bool check[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int res = -987654321;

void solution(int sum, int cnt)
{
  if (cnt == k)
  {
    if (res <= sum)
      res = sum;
    return;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (check[i][j])
        continue;
      bool isOk = true;
      for (int t = 0; t < 4; t++)
      {
        int nx = i + dx[t];
        int ny = j + dy[t];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
          if (check[nx][ny])
            isOk = false;
        }
      }
      if (isOk)
      {
        check[i][j] = true;
        solution(sum + arr[i][j], cnt + 1);
        check[i][j] = false;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  solution(0, 0);

  cout << res << '\n';

  return 0;
}