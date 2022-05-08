#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testcase = 0;

  cin >> testcase;
  stack<int> s;

  while (testcase--)
  {
    string cmd = "";
    int num = 0;
    cin >> cmd;

    if (cmd == "push")
    {
      cin >> num;
      s.push(num);
    }
    else if (cmd == "pop")
    {
      if (s.empty())
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << s.top() << '\n';
        s.pop();
      }
    }
    else if (cmd == "size")
    {
      cout << s.size() << '\n';
    }
    else if (cmd == "empty")
    {
      if (s.empty())
      {
        cout << 1 << '\n';
      }
      else
      {
        cout << 0 << '\n';
      }
    }
    else if (cmd == "top")
    {
      if (s.empty())
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << s.top() << '\n';
      }
    }
  }

  return 0;
}
