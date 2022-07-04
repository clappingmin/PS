#include <iostream>

using namespace std;

int n, m; // 1부터 n까지의 자연수 중 m개를 고른 수열
int arr[9];
bool check[9];

void go(int index)
{
  if (index == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr[i] << " ";
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++)
  {
    if (check[i])
      continue;

    arr[index] = i;
    check[i] = true;
    go(index + 1);
    check[i] = false;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  go(0);

  return 0;
}
