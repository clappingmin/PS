#include <iostream>
#include <algorithm>
#define MAX 20 + 1

using namespace std;

int n;
int team[MAX][MAX];
int res = 987654321;
bool check[MAX];

int calc_team()
{
  int start = 0, link = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (check[i] == true && check[j] == true)
        start += team[i][j];
      else if (check[i] == false && check[j] == false)
        link += team[i][j];
    }
  }
  return abs(start - link);
}

void choice_team(int idx)
{
  if (idx == n + 1)
  {
    res = min(res, calc_team());
    return;
  }

  check[idx] = true;
  choice_team(idx + 1);
  check[idx] = false;
  choice_team(idx + 1);
}

int main()
{
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> team[i][j];
    }
  }

  choice_team(1);

  cout << res << '\n';

  return 0;
}