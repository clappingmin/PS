#include <iostream>
#include <vector>

using namespace std;

int n;
int res = 0;
vector<int> output;

void solution(int now, int want)
{
  if (now == want)
  {
    res += 1;
    return;
  }
  if (now + 1 <= want)
    solution(now + 1, want);

  if (now + 2 <= want)
    solution(now + 2, want);

  if (now + 3 <= want)
    solution(now + 3, want);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  while (n--)
  {
    int num;
    res = 0;
    cin >> num;

    solution(0, num);
    output.push_back(res);
  }

  for (int i = 0; i < output.size(); i++)
    cout << output[i] << '\n';

  return 0;
}