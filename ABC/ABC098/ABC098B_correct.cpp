#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 1; i < n; i++)
  {
    int cnt = 0;

    for (char c = 'a'; c <= 'z'; c++)
    {
      bool left = false, right = false;

      for (int j = 0; j < i; j++)
        if (s[j] == c)
          left = true;

      for (int j = i; j < n; j++)
        if (s[j] == c)
          right = true;

      if (left && right)
        cnt++;
    }
    if (ans < cnt)
      ans = cnt;
  }
  cout << ans << endl;
}
