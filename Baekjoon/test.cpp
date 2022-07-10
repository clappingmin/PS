#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> input;
int output[9];

void go(int index, int start)
{
  if (index == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << output[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = start; i < n; i++)
  {
    output[index] = input[i];
    go(index + 1, i);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    input.push_back(num);
  }

  sort(input.begin(), input.end());

  go(0, 0);

  return 0;
}