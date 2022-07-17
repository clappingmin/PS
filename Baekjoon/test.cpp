#include <iostream>

using namespace std;

int n;
int t[16];
int p[16];
int res = 0;

void go(int day, int pay)
{
  if (day == n + 1) // 퇴사하는 날
  {
    if (res < pay)
      res = pay;
    return;
  }

  if (day > n + 1)
    return;

  go(day + t[day], pay + p[day]);
  go(day + 1, pay);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> t[i] >> p[i];
  }

  go(1, 0);

  cout << res << '\n';

  return 0;
}