#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int n;
int team[MAX + 1][MAX + 1];
int res = 987654321;
bool check[MAX + 1];

int calc_team()
{
  int start = 0, link = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (check[i] == true && check[j] == true)
      {
        start += team[i][j];
      }
      else if (check[i] == false && check[j] == false)
      {
        link += team[i][j];
      }
    }
  }
  return abs(start - link); // 절대값
}

void choice_team(int idx, int cnt)
{
  if (cnt == n / 2)
  {
    res = min(res, calc_team());
    return;
  }

  for (int i = idx; i <= n; i++)
  {
    if (check[i])
      continue;

    check[i] = true;
    choice_team(i, cnt + 1);
    check[i] = false;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> team[i][j];
    }
  }

  choice_team(1, 0);

  cout << res << '\n';

  return 0;
}